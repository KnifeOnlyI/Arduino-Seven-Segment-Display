/*
 * This program show random number on a seven-segment display.
 * The seven-segment display pins are :
 * 
 *      1
 * 2         3
 *      4
 * 5         6
 *      7 
 */

const int OUT_1 = 2;
const int OUT_2 = 3;
const int OUT_3 = 4;
const int OUT_4 = 5;
const int OUT_5 = 6;
const int OUT_6 = 7;
const int OUT_7 = 8;

const int DELAY_TIMER_TEST = 1000;
const int DELAY_TIMER = 5000;

void setup()
{
  pinMode(OUT_1, OUTPUT);
  pinMode(OUT_2, OUTPUT);
  pinMode(OUT_3, OUTPUT);
  pinMode(OUT_4, OUTPUT);
  pinMode(OUT_5, OUTPUT);
  pinMode(OUT_6, OUTPUT);
  pinMode(OUT_7, OUTPUT);

  randomSeed(analogRead(0));

  executeTest();
}

void loop()
{
  // Show a random number in interval [0;9]
  showNumber(random(0, 10));

  delay(DELAY_TIMER);
  setAllOutOff();

  setAllOutOn();
}

/**
 * Execute a test program to test if all leds are connected.
 * Show all numbers in a row on the board.
 */
void executeTest()
{
  setAllOutOn();
  delay(DELAY_TIMER_TEST);

  for (int i = 0; i < 10; i++)
  {
    showNumber(i);
    delay(DELAY_TIMER_TEST);
  }

  setAllOutOff();

  delay(DELAY_TIMER_TEST);
}

/**
 * Turn on the corresponding leds on the board to the of the specified number.
 * Turn off all leds if number not in [1;6].
 */
void showNumber(int number)
{
  setAllOutOff();

  switch (number)
  {
  case 0:
    setOutState(OUT_1, true);
    setOutState(OUT_2, true);
    setOutState(OUT_3, true);
    setOutState(OUT_5, true);
    setOutState(OUT_6, true);
    setOutState(OUT_7, true);
    break;
  case 1:
    setOutState(OUT_3, true);
    setOutState(OUT_6, true);
    break;

  case 2:
    setOutState(OUT_1, true);
    setOutState(OUT_3, true);
    setOutState(OUT_4, true);
    setOutState(OUT_5, true);
    setOutState(OUT_7, true);
    break;

  case 3:
    setOutState(OUT_1, true);
    setOutState(OUT_3, true);
    setOutState(OUT_4, true);
    setOutState(OUT_6, true);
    setOutState(OUT_7, true);
    break;

  case 4:
    setOutState(OUT_2, true);
    setOutState(OUT_3, true);
    setOutState(OUT_4, true);
    setOutState(OUT_6, true);
    break;

  case 5:
    setOutState(OUT_1, true);
    setOutState(OUT_2, true);
    setOutState(OUT_4, true);
    setOutState(OUT_6, true);
    setOutState(OUT_7, true);
    break;

  case 6:
    setOutState(OUT_1, true);
    setOutState(OUT_2, true);
    setOutState(OUT_4, true);
    setOutState(OUT_5, true);
    setOutState(OUT_6, true);
    setOutState(OUT_7, true);
    break;

  case 7:
    setOutState(OUT_1, true);
    setOutState(OUT_2, true);
    setOutState(OUT_3, true);
    setOutState(OUT_6, true);
    break;

  case 8:
    setAllOutOn();
    break;

  case 9:
    setOutState(OUT_1, true);
    setOutState(OUT_2, true);
    setOutState(OUT_3, true);
    setOutState(OUT_4, true);
    setOutState(OUT_6, true);
    setOutState(OUT_7, true);
    break;

  default:
    setAllOutOff();
  }
}

/**
 * Turn on all leds.
 */
void setAllOutOn()
{
  setOutState(OUT_1, true);
  setOutState(OUT_2, true);
  setOutState(OUT_3, true);
  setOutState(OUT_4, true);
  setOutState(OUT_5, true);
  setOutState(OUT_6, true);
  setOutState(OUT_7, true);
}

/**
 * Turn off all leds.
 */
void setAllOutOff()
{
  setOutState(OUT_1, false);
  setOutState(OUT_2, false);
  setOutState(OUT_3, false);
  setOutState(OUT_4, false);
  setOutState(OUT_5, false);
  setOutState(OUT_6, false);
  setOutState(OUT_7, false);
}

/**
 * Set the state of the specified out pin.
 */
void setOutState(int out, bool on)
{
  digitalWrite(out, on ? LOW : HIGH);
}
