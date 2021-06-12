LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

ENTITY part1 IS
  PORT(	
		CLOCK_50 : IN    	std_logic;
		Reset_n	: IN		std_logic;
      KEY      : IN    	std_logic;
      LEDR     : OUT   	std_logic_vector(7 DOWNTO 0)
       );
END part1;

ARCHITECTURE Structure OF part1 IS

	component nios_system is
		port (
			clk_clk       : in  std_logic                    := 'X'; -- clk
			key_export    : in  std_logic                    := 'X'; -- export
			leds_export   : out std_logic_vector(7 downto 0);        -- export
			reset_reset_n : in  std_logic                    := 'X'  -- reset_n
		);
	end component nios_system;
	
begin

	u0 : component nios_system
		port map (
			clk_clk       => CLOCK_50, -- clk.clk
			key_export    => KEY,    	-- key.export
			leds_export   => LEDR,   	-- leds.export
			reset_reset_n => Reset_n  	-- reset.reset_n
		);

END ARCHITECTURE Structure;
