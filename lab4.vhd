LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.ALL;
USE ieee.numeric_std.ALL;

ENTITY lab4 IS
	GENERIC(
		max_count :integer range 0 to 1000000 := 1000000
		);
	PORT(
		clk        		: IN std_logic;          				-- 50 Mhz system clock
		reset_n    		: IN std_logic;          				-- active low system reset
		write      		: IN std_logic;          				-- active high write enable
		address    		: IN std_logic;  						--address of register to be written to (from CPU)
		writedata 		: IN std_logic_vector(31 DOWNTO 0);  	--data from the CPU to be stored in the component
		--
		out_wave_export : OUT std_logic;  	--data visible to other components
		irq 			: OUT std_logic  						--signal to interrupt the processor                      
		);
END ENTITY lab4;

architecture beh of lab4 is

type ram_type is array (1 downto 0) of std_logic_vector (31 downto 0);
signal Registers : ram_type;

signal pc_sig : integer range 0 to max_count := 0;
constant angle_min : std_logic_vector(31 downto 0) := x"0000c350";
constant angle_max : std_logic_vector(31 downto 0) := x"000186a0";
signal angle_count : std_logic_vector(31 downto 0);

type state_type is (int_right, int_left, sweep_right, sweep_left);
signal state_reg : state_type := int_right;
signal state_next : state_type;

--signal	write      		:  std_logic := '1';          				-- active high write enable
--signal	address    		:  std_logic := '1';  						--address of register to be written to (from CPU)
--signal	writedata 		:  std_logic_vector(31 DOWNTO 0) := x"000186a0";  	--data from the CPU to be stored in the component

begin

reg_set: process(clk, reset_n,address,write)
	begin
		if (reset_n = '0') then
			Registers(0) <= angle_min;
			Registers(1) <= angle_max;
		elsif (clk'event and clk = '1') then
			if (write = '1') then
				if (address = '0') then
					Registers(0) <= writedata;
				elsif (address = '1') then
					Registers(1) <= writedata;
				end if;
			end if;
		end if;
	end process;

period_counter: process(clk,reset_n,pc_sig)
	begin
		if (reset_n = '0') then
			pc_sig <= 0;
		elsif (clk'event and clk = '1') then
			if (pc_sig = max_count) then
				pc_sig <= 0;
			else
				pc_sig <= pc_sig + 1;
			end if;
		end if;
	end process;

angle_counter: process(clk,pc_sig,reset_n,state_reg)
	begin
	if (clk'event and clk = '1') then
		if (reset_n = '0') then
			angle_count <= angle_min;
		elsif (pc_sig = 0) then
			if (state_reg = sweep_left) then
				angle_count <= angle_count + 500;
			elsif (state_reg = sweep_right) then
				angle_count <= angle_count - 500;
			else
				angle_count <= angle_count;
			end if;
		end if;
	end if;
	end process;

out_wave_export <= 	'1' when pc_sig < angle_count else
					'0';
		
interrupts: process(clk,state_reg)
	begin
		if (clk'event and clk = '1') then
			if (state_reg = int_right) then
				irq <= '1';
			elsif (state_reg = int_left) then
				irq <= '1';
			else
				irq <= '0';
			end if;
		end if;
	end process;
			
state_register: process(clk,reset_n)
	begin
		if(reset_n = '0') then
			state_reg <= int_right;
		elsif (clk'event and clk = '1') then
			state_reg <= state_next;
		end if;
	end process;
	
next_state_logic: process(state_reg,write,angle_count,Registers,state_next)
	begin
		state_next <= state_reg;
		case state_reg is
			when int_right => 
				if (write = '1') then
					state_next <= sweep_left;
				else
					state_next <= int_right;
				end if;
			when sweep_left => 
				if (angle_count >= Registers(1)) then
					state_next <= int_left;
				else
					state_next <= sweep_left;
				end if;
			when int_left => 
				if (write = '1') then
					state_next <= sweep_right;
				else
					state_next <= int_left;
				end if;
			when sweep_right => 
				if (angle_count <= Registers(0)) then
					state_next <= int_right;
				else
					state_next <= sweep_right;
				end if;
			when others => 
				state_next <= state_next;
		end case;
	end process;
end beh;