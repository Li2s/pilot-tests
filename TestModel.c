#include "unity.h"
#include <stdbool.h>
#include "sensor.h"

/*--------------------------------------------------------------------*/
void test_SDD_SW_REQ_2(void)
{
    bool is_float = __builtin_types_compatible_p(typeof(getVoltageAdc(1000)), float);
    TEST_ASSERT_TRUE(is_float);
}

/*--------------------------------------------------------------------*/
void test_SDD_SW_REQ_3(void)
{
    uint16_t l_adc_raw = 15;
    float result = (3.3/4096)*l_adc_raw;
    float voltageAdc = getVoltageAdc(l_adc_raw);
    
    TEST_ASSERT_EQUAL(result, voltageAdc);
}

/*--------------------------------------------------------------------*/
void test_SDD_SW_REQ_4(void)
{
    bool is_float = __builtin_types_compatible_p(typeof(getRotationAngle(1)), float);
    TEST_ASSERT_TRUE(is_float);
}

/*--------------------------------------------------------------------*/
void test_SDD_SW_REQ_5(void)
{
    float l_voltage_adc = 2;
    float result = (90/3.3)*l_voltage_adc;
    float rotationAngle = getRotationAngle(l_voltage_adc);
    
    TEST_ASSERT_EQUAL(result, rotationAngle);
    
}

/*--------------------------------------------------------------------*/
void test_SDD_SW_REQ_6(void)
{
    float l_adc_raw = -1;
    float h_adc_raw = 4096;
    
    TEST_ASSERT_EQUAL(0, checkValueAdc(l_adc_raw));
    TEST_ASSERT_EQUAL(0, checkValueAdc(h_adc_raw));
}

/*--------------------------------------------------------------------*/
void test_SDD_SW_REQ_7(void)
{
    // ???
    float l_adc_raw = -1;
    float h_adc_raw = 4096;
    
    TEST_ASSERT_EQUAL(0, checkValueAdc(l_adc_raw));
    TEST_ASSERT_EQUAL(0, checkValueAdc(h_adc_raw));
}

/*--------------------------------------------------------------------*/
void test_SDD_SW_REQ_10(void)
{
    float l_voltage_adc = 0;
    float h_voltage_adc = 3.3;
    
    TEST_ASSERT_EQUAL(0, getRotationAngle(l_voltage_adc));
    TEST_ASSERT_EQUAL(0, getRotationAngle(h_voltage_adc));
}



