#include <Ethernet.h>
#include <ArduinoHA.h>
#include <JC_Button.h>

#define LED_PIN1 22
#define LED_PIN2 23
#define LED_PIN3 24
#define LED_PIN4 25
#define LED_PIN5 26
#define LED_PIN6 27
#define LED_PIN7 28
#define LED_PIN8 29

#define BUTTON_PIN1      40
#define BUTTON_NAME1     "mybtn1"
#define BUTTON_PIN2      41
#define BUTTON_NAME2     "mybtn2"
#define BUTTON_PIN3      42
#define BUTTON_NAME3     "mybtn3"
#define BUTTON_PIN4      43
#define BUTTON_NAME4     "mybtn4"
#define BUTTON_PIN5      44
#define BUTTON_NAME5     "mybtn5"
#define BUTTON_PIN6      45
#define BUTTON_NAME6     "mybtn6"
#define BUTTON_PIN7      46
#define BUTTON_NAME7     "mybtn7"
#define BUTTON_PIN8      47
#define BUTTON_NAME8     "mybtn8"


#define BROKER_ADDR IPAddress(192,168,0,17)

byte mac[] = {0x00, 0x10, 0xFA, 0x6E, 0x38, 0x4A};

EthernetClient client;
HADevice device(mac, sizeof(mac));
HAMqtt mqtt(client, device, 20);

// devices types go here
HASwitch switch1("mySwitch1");
HASwitch switch2("mySwitch2");
HASwitch switch3("mySwitch3");
HASwitch switch4("mySwitch4");
HASwitch switch5("mySwitch5");
HASwitch switch6("mySwitch6");
HASwitch switch7("mySwitch7");
HASwitch switch8("mySwitch8");

HADeviceTrigger shortPressTrigger1(HADeviceTrigger::ButtonShortPressType, BUTTON_NAME1);
HADeviceTrigger longPressTrigger1(HADeviceTrigger::ButtonLongPressType, BUTTON_NAME1);
Button btn1(BUTTON_PIN1);
bool holdingBtn1 = false;

HADeviceTrigger shortPressTrigger2(HADeviceTrigger::ButtonShortPressType, BUTTON_NAME2);
HADeviceTrigger longPressTrigger2(HADeviceTrigger::ButtonLongPressType, BUTTON_NAME2);
Button btn2(BUTTON_PIN2);
bool holdingBtn2 = false;

HADeviceTrigger shortPressTrigger3(HADeviceTrigger::ButtonShortPressType, BUTTON_NAME3);
HADeviceTrigger longPressTrigger3(HADeviceTrigger::ButtonLongPressType, BUTTON_NAME3);
Button btn3(BUTTON_PIN3);
bool holdingBtn3 = false;

HADeviceTrigger shortPressTrigger4(HADeviceTrigger::ButtonShortPressType, BUTTON_NAME4);
HADeviceTrigger longPressTrigger4(HADeviceTrigger::ButtonLongPressType, BUTTON_NAME4);
Button btn4(BUTTON_PIN4);
bool holdingBtn4 = false;

HADeviceTrigger shortPressTrigger5(HADeviceTrigger::ButtonShortPressType, BUTTON_NAME5);
HADeviceTrigger longPressTrigger5(HADeviceTrigger::ButtonLongPressType, BUTTON_NAME5);
Button btn5(BUTTON_PIN5);
bool holdingBtn5 = false;

HADeviceTrigger shortPressTrigger6(HADeviceTrigger::ButtonShortPressType, BUTTON_NAME6);
HADeviceTrigger longPressTrigger6(HADeviceTrigger::ButtonLongPressType, BUTTON_NAME6);
Button btn6(BUTTON_PIN6);
bool holdingBtn6 = false;

HADeviceTrigger shortPressTrigger7(HADeviceTrigger::ButtonShortPressType, BUTTON_NAME7);
HADeviceTrigger longPressTrigger7(HADeviceTrigger::ButtonLongPressType, BUTTON_NAME7);
Button btn7(BUTTON_PIN7);
bool holdingBtn7 = false;

HADeviceTrigger shortPressTrigger8(HADeviceTrigger::ButtonShortPressType, BUTTON_NAME8);
HADeviceTrigger longPressTrigger8(HADeviceTrigger::ButtonLongPressType, BUTTON_NAME8);
Button btn8(BUTTON_PIN8);
bool holdingBtn8 = false;

void onSwitchCommand(bool state, HASwitch* sender)
{
    if (sender == &switch1) {
        digitalWrite(LED_PIN1, (state ? HIGH : LOW));
    } else if (sender == &switch2) {
        digitalWrite(LED_PIN2, (state ? HIGH : LOW));
    } else if (sender == &switch3) {
        digitalWrite(LED_PIN3, (state ? HIGH : LOW));
    } else if (sender == &switch4) {
        digitalWrite(LED_PIN4, (state ? HIGH : LOW));
    } else if (sender == &switch5) {
        digitalWrite(LED_PIN5, (state ? HIGH : LOW));
    } else if (sender == &switch6) {
        digitalWrite(LED_PIN6, (state ? HIGH : LOW));
    } else if (sender == &switch7) {
        digitalWrite(LED_PIN7, (state ? HIGH : LOW));
    } else if (sender == &switch8) {
        digitalWrite(LED_PIN8, (state ? HIGH : LOW));
    } 

    sender->setState(state); // report state back to the Home Assistant
}

void setup() {
    pinMode(LED_PIN1, OUTPUT);
    digitalWrite(LED_PIN1, LOW);

    pinMode(LED_PIN2, OUTPUT);
    digitalWrite(LED_PIN2, LOW);

    pinMode(LED_PIN3, OUTPUT);
    digitalWrite(LED_PIN3, LOW);

    pinMode(LED_PIN4, OUTPUT);
    digitalWrite(LED_PIN4, LOW);

    pinMode(LED_PIN5, OUTPUT);
    digitalWrite(LED_PIN5, LOW);

    pinMode(LED_PIN6, OUTPUT);
    digitalWrite(LED_PIN6, LOW);

    pinMode(LED_PIN7, OUTPUT);
    digitalWrite(LED_PIN7, LOW);

    pinMode(LED_PIN8, OUTPUT);
    digitalWrite(LED_PIN8, LOW);
    
    // you don't need to verify return status
    Ethernet.begin(mac);

    switch1.setName("led1");
    switch1.setIcon("mdi:lightbulb");
    switch1.onCommand(onSwitchCommand);
    
    switch2.setName("led2");
    switch2.setIcon("mdi:lightbulb");
    switch2.onCommand(onSwitchCommand);
    
    switch3.setName("led3");
    switch3.setIcon("mdi:lightbulb");
    switch3.onCommand(onSwitchCommand);
    
    switch4.setName("led4");
    switch4.setIcon("mdi:lightbulb");
    switch4.onCommand(onSwitchCommand);
    
    switch5.setName("led5");
    switch5.setIcon("mdi:lightbulb");
    switch5.onCommand(onSwitchCommand);

    switch6.setName("led6");
    switch6.setIcon("mdi:lightbulb");
    switch6.onCommand(onSwitchCommand);
    
    switch7.setName("led7");
    switch7.setIcon("mdi:lightbulb");
    switch7.onCommand(onSwitchCommand);

    switch8.setName("led8");
    switch8.setIcon("mdi:lightbulb");
    switch8.onCommand(onSwitchCommand);

    btn1.begin();
    btn2.begin();
    btn3.begin();
    btn4.begin();
    btn5.begin();
    btn6.begin();
    btn7.begin();
    btn8.begin();

    mqtt.begin("192.168.0.17", 1883, "homeassistant", "Ithoex8tailoo2oeGaeza4ai7ie9iceishue9vuNeemi0aigeey3QuegaefouMol");
}

void loop() {
    Ethernet.maintain();
    mqtt.loop();
    btn1.read();

    if (btn1.pressedFor(3000) && !holdingBtn1) {
        longPressTrigger1.trigger();
        holdingBtn1 = true;
    } else if (btn1.wasReleased()) {
        if (holdingBtn1) {
            holdingBtn1 = false;
        } else {
            shortPressTrigger1.trigger();
        }
    }

    btn2.read();

    if (btn2.pressedFor(3000) && !holdingBtn2) {
        longPressTrigger2.trigger();
        holdingBtn2 = true;
    } else if (btn2.wasReleased()) {
        if (holdingBtn2) {
            holdingBtn2 = false;
        } else {
            shortPressTrigger2.trigger();
        }
    }

    btn3.read();

    if (btn3.pressedFor(3000) && !holdingBtn3) {
        longPressTrigger3.trigger();
        holdingBtn3 = true;
    } else if (btn3.wasReleased()) {
        if (holdingBtn3) {
            holdingBtn3 = false;
        } else {
            shortPressTrigger3.trigger();
        }
    }

    btn4.read();

    if (btn4.pressedFor(3000) && !holdingBtn4) {
        longPressTrigger4.trigger();
        holdingBtn4 = true;
    } else if (btn4.wasReleased()) {
        if (holdingBtn4) {
            holdingBtn4 = false;
        } else {
            shortPressTrigger4.trigger();
        }
    }

    btn5.read();

    if (btn5.pressedFor(3000) && !holdingBtn5) {
        longPressTrigger5.trigger();
        holdingBtn5 = true;
    } else if (btn5.wasReleased()) {
        if (holdingBtn5) {
            holdingBtn5 = false;
        } else {
            shortPressTrigger5.trigger();
        }
    }

    btn6.read();

    if (btn6.pressedFor(3000) && !holdingBtn6) {
        longPressTrigger6.trigger();
        holdingBtn6 = true;
    } else if (btn6.wasReleased()) {
        if (holdingBtn6) {
            holdingBtn6 = false;
        } else {
            shortPressTrigger6.trigger();
        }
    }

    btn6.read();

    if (btn7.pressedFor(3000) && !holdingBtn7) {
        longPressTrigger7.trigger();
        holdingBtn7 = true;
    } else if (btn7.wasReleased()) {
        if (holdingBtn7) {
            holdingBtn7 = false;
        } else {
            shortPressTrigger7.trigger();
        }
    }

    btn8.read();

    if (btn8.pressedFor(3000) && !holdingBtn8) {
        longPressTrigger8.trigger();
        holdingBtn8 = true;
    } else if (btn8.wasReleased()) {
        if (holdingBtn8) {
            holdingBtn8 = false;
        } else {
            shortPressTrigger8.trigger();
        }
    }
}
