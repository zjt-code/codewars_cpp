#include<stdio.h>
#include<stdint.h>

#define NUM_OF_SAMPLES   10


uint32_t samplingBuffer[]=
{
 -420,
 -419,
 -400,
 -432,
 -444,
 -432,
 -437,
 -433,
 -419,
-438,
};

static int32_t convert_to_mv(uint32_t raw)
{
 // return raw * 1814 / 0xFFF;  // 12 bit adc

   // Use internal bandgap (supply voltage in 1210mV) as reference
   //iadcCfgAnalogGain0P5x;

  return (int32_t)raw;
    //return raw * 4840 / 0xFFFF;  // 16 bit adc
}


int32_t le_voltage_monitor_get_average_mv(void)
{
  int32_t avg = 0;
for(int32_t i = 0; i < NUM_OF_SAMPLES; i++)
  //for(int32_t i = 0; i < 10; i++)
  {
    avg += convert_to_mv(samplingBuffer[i]);

    // if(i < 10)
    // app_log_info("samplingbuff[%d]= 0x%08x\r\n", i, samplingBuffer[i]);
  }
  return ((int16_t)avg / NUM_OF_SAMPLES);
}



int main()
{

    int32_t a = -300;

    uint32_t b  =(uint32_t)a;

    
    if( b > 0)printf(" b is biger than 0\r\n");

    uint32_t c = 0xffffff9c;

    int32_t d = (int32_t)c;

    printf("a = 0x%08x\r\n", a);
    printf("b = 0x%u\r\n", a + 200u);

    printf("d = %d\r\n",d);


    printf("hello world\r\n");


    int32_t data_mV = le_voltage_monitor_get_average_mv();


    printf("data_mv = %d\r\n",(uint16_t)data_mV);

}