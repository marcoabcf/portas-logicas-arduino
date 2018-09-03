/**
 * CONSTS
 */
const byte LED_RED = 11;
const byte LED_BLUE = 12;
const byte LED_GREEN = 13;

/**
 * FUNCTIONS
 */
void condOr(int);
void condAnd(int);
void condNor(int);
void condNand(int);
void condOrExclusive(int);
void condNorExclusive(int);

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int i, inputs[8][3] = {{0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};
  
  Serial.println();
  for (i = 0; i < 8; i++) {
    int signalRed = inputs[i][0];
    int signalBlue = inputs[i][1];
    int signalGreen = inputs[i][2];

    Serial.println(signalRed);
    Serial.println(signalBlue);
    Serial.println(signalGreen);

    condAnd(signalRed, signalBlue, signalGreen);

    delay(2000);
    offLeds();
    
    condNand(signalRed, signalBlue, signalGreen);

    delay(2000);
    offLeds();
    
    condOr(signalRed, signalBlue, signalGreen);
    
    delay(2000);
    offLeds();
    
    condNor(signalRed, signalBlue, signalGreen);

    delay(2000);
    offLeds();

    condOrExclusive(signalRed, signalBlue, signalGreen);

    delay(2000);
    offLeds();

    condNorExclusive(signalRed, signalBlue, signalGreen);

    delay(2000);
    offLeds();
    Serial.println();
  }

  delay(1000);
}


/**
 * .
 *
 * @param int signalRed
 * @param int signalBlue
 * @param int signalGreen
 */
void condAnd(int signalRed, int signalBlue, int signalGreen)
{
  Serial.println("AND...");
  if((signalRed * signalBlue * signalGreen) == 1) {
    digitalWrite(LED_RED, signalRed);
    digitalWrite(LED_BLUE, signalBlue);
    digitalWrite(LED_GREEN, signalGreen);
  }
}

/**
 * .
 *
 * @param int signalRed
 * @param int signalBlue
 * @param int signalGreen
 */
void condNand(int signalRed, int signalBlue, int signalGreen)
{
  Serial.println("NAND...");
  if(!(signalRed * signalBlue * signalGreen)) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_GREEN, HIGH);
  }
}


/**
 * .
 *
 *
 * @param int signalRed
 * @param int signalBlue
 * @param int signalGreen
 */
void condOr(int signalRed, int signalBlue, int signalGreen)
{
  Serial.println("OR...");
  if((signalRed + signalBlue + signalGreen) > 0) {
    digitalWrite(LED_RED, signalRed);
    digitalWrite(LED_BLUE, signalBlue);
    digitalWrite(LED_GREEN, signalGreen);
  }
}

/**
 * .
 *
 *
 * @param int signalRed
 * @param int signalBlue
 * @param int signalGreen
 */
void condNor(int signalRed, int signalBlue, int signalGreen)
{
  Serial.println("NOR...");
  if(!((signalRed + signalBlue + signalGreen) > 0)) {
    digitalWrite(LED_RED, !signalRed);
    digitalWrite(LED_BLUE, !signalBlue);
    digitalWrite(LED_GREEN, !signalGreen);
  }
}

/**
 * .
 *
 *
 * @param int signalRed
 * @param int signalBlue
 * @param int signalGreen
 */
void condOrExclusive(int signalRed, int signalBlue, int signalGreen)
{
  Serial.println("OR EXCLUSIVE...");
  if((signalRed != signalBlue) != signalGreen) {
    digitalWrite(LED_RED, signalRed);
    digitalWrite(LED_BLUE, signalBlue);
    digitalWrite(LED_GREEN, signalGreen);
  }
}

/**
 * .
 *
 *
 * @param int signalRed
 * @param int signalBlue
 * @param int signalGreen
 */
void condNorExclusive(int signalRed, int signalBlue, int signalGreen)
{
  Serial.println("NOR EXCLUSIVE...");
  if(!((signalRed != signalBlue) != signalGreen)) {
    digitalWrite(LED_RED, !signalRed);
    digitalWrite(LED_BLUE, !signalBlue);
    digitalWrite(LED_GREEN, !signalGreen);
  }
}

void offLeds()
{
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_GREEN, LOW);
}
