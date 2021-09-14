/////////////////////////////////////////////////////////////////////
// the implementation of problem 1, sampled signal generator with certain sampling frequency and duration
////////////////////////////////////////////////////////////////////
#include <iostream>
#define _USE_MATH_DEFINES 
#include <cmath>
//function to implement sampled signal generator

// input args:
//    float amplitude: amplitude of sine wave signal
//    float frequency_origin_sine: foundamental frequency of sine signal
//    float frequency_origin_square: foundamental frequency of symmetric squared wave signal
//    float phase_shift: phase shift of sine signal
//    float frequency_sample: sampling frequncy
//    float duration: sampling time duration    
// output args:
//    data_buffer: sampled sine signal in the data buffer
//    data_buffer_squared: sampled squared wave signal in the data buffer
//    mixed_signal: mixed signal
//    mean_first_quarter: mean of mixed signal in the first quarter
//    integral: discrete integral of mixed signal in the second quarter

float sampled_signal_generator(float amplitude, float frequency_origin_sine, float frequency_origin_square, float phase_shift,float frequency_sample, float duration)

{
    // calculated number of sample data points
    int max_number= duration/(1/frequency_sample);
    
    // sampled time interval
    float time_interval_sample=1/frequency_sample;
 
    //period of original signal for squared wave signal
    float period_original_signal=1/ frequency_origin_square;
    //initialize data buffer for mixed signal, sine signal and symmetric squared wave signal
    float data_buffer[max_number] = {0 };
    float data_buffer_squared[max_number] = {0};
    float mixed_signal[max_number] = {0};
    //initialize sum of mixed signal and integral of second quarter
    float mixed_signal_sum =0;
    float integral = 0;
    int a=0;
    //for loop to loop over sampled data
    for (int i=0; i<max_number;i++)
    {

        //calculate sampled sine signal at certain time point 
        data_buffer[i]=  amplitude*sin(2*M_PI*frequency_origin_sine*time_interval_sample*i+phase_shift);
        // 
        //calualte local time point for ith sampled signal
        float local_time=i*time_interval_sample;
        
        // calculate remainder of local time point with respect to period of original signal
        float remainder= fmod(local_time , period_original_signal);
       // printf("remaider is %g\n",remainder);
        if (remainder  <= 0.5*period_original_signal)
        {
           data_buffer_squared[i] = 1;
        }
        else
        {
            data_buffer_squared[i] =-1;
        }
        
        // calculate mixed signal by multiplying two signals together
        mixed_signal[i] = data_buffer_squared[i] *data_buffer[i];
        // sum up mixed signal in first quarter
        if (local_time <= 0.25*duration)
        {
            mixed_signal_sum += mixed_signal[i];
            a++;
            
        }
        
        // calculate integral of mixed signal in the second quarter
        if (0.25*duration < local_time <= 0.5*duration)
        {
           integral+=time_interval_sample*mixed_signal[i];
        }

        // print sampled sine signal, squared wave signal and mixed signal
        printf("sampled sine signal is: %f\n", data_buffer[i]);
        printf("sampled symmetric squared wave signal is: %f\n", data_buffer_squared[i]);
        printf("mixed signal is: %f\n", mixed_signal[i]);

        
       
    }
    //calculate mean of first quarter of mixed signal
    float mean_first_quarter = mixed_signal_sum /a;
    
    
     // print mean of first quarter of mixed signal
    printf("mean of mixed signal in the first quarter is : %g\n", mean_first_quarter);
    //print discrete integral of mixed signal in the first quarter
    printf("Integral of mixed signal in the second quarter is : %g\n", integral);
    

  
   
    return data_buffer,data_buffer_squared,mixed_signal,mean_first_quarter,integral;
}
// driver code
int main()
{
   //initialize parameters
   float amplitude =3;
   float frequency_origin_sine=10; // unit: Hz
   float frequency_origin_square=40;// unit: Hz
   float phase_shift= 90;// unit: celsius degree
   float frequency_sample = 200; // unit: Hz
   float duration=1; //unit: s
   // function call
   float data_buffer,data_buffer_squared,mixed_signal,mean_first_quarter,integral = sampled_signal_generator(amplitude,frequency_origin_sine,frequency_origin_square,phase_shift,frequency_sample,duration);


}

