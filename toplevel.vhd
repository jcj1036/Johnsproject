LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.ALL;
USE ieee.numeric_std.ALL;

ENTITY toplevel IS
	PORT(
		CLOCK_50 : IN    	std_logic;
		Reset_n	: IN		std_logic;
		KEY      : in  std_logic_vector(2 downto 1);
		SW		   : in std_logic_vector (7 downto 0);

		HEX0     : out std_logic_vector(6 downto 0);
		HEX1     : out std_logic_vector(6 downto 0);
		HEX2     : out std_logic_vector(6 downto 0);
		HEX4     : out std_logic_vector(6 downto 0);
		HEX5     : out std_logic_vector(6 downto 0);
		
		pin_out	: out std_logic
		);
END ENTITY toplevel;

architecture structure of toplevel is

	component nios_system is
		port (
			clk_clk              : in  std_logic                    := 'X';             -- clk
			reset_reset_n        : in  std_logic                    := 'X';             -- reset_n
			switches_export      : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			pushbuttons_export   : in  std_logic_vector(3 downto 0) := (others => 'X'); -- export
			hex5_export          : out std_logic_vector(6 downto 0);                    -- export
			hex4_export          : out std_logic_vector(6 downto 0);                    -- export
			hex3_export          : out std_logic_vector(6 downto 0);                    -- export
			hex2_export          : out std_logic_vector(6 downto 0);                    -- export
			hex1_export          : out std_logic_vector(6 downto 0);                    -- export
			servocontroller_name : out std_logic                                        -- name
		);
	end component nios_system;
	
begin

	u0 : component nios_system
		port map (
			clk_clk              => CLOCK_50,              --             clk.clk
			reset_reset_n        => Reset_n,        --           reset.reset_n
			switches_export      => SW,      --        switches.export
			pushbuttons_export(2 downto 1)   => KEY,   --     pushbuttons.export
			hex5_export          => HEX5,          --            hex5.export
			hex4_export          => HEX4,          --            hex4.export
			hex3_export          => HEX2,          --            hex3.export
			hex2_export          => HEX1,          --            hex2.export
			hex1_export          => HEX0,          --            hex1.export
			servocontroller_name => pin_out  -- servocontroller.name
		);
		
end architecture structure;