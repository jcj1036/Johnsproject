int NoiseFilter(long inputX, int sampleNumber)
{  
  // Starting with a generic FIR filter impelementation customize only by
  // changing the length of the filter using MFILT and the values of the
  // impulse response in h

  // Filter type: FIR
 
  //
  //  Set the constant HFXPT to the sum of the values of the impulse response
  //  This is to keep the gain of the impulse response at 1.
  //
  // LPF FIR Filter Coefficients MFILT = 60, Fc = 85
  const int HFXPT = 4096, MFILT = 60;
  int h[] = {3, 1, -3, -5, -4, 1, 8, 11, 4, -10, -21, -18, 4, 31,
  40, 17, -30, -67, -57, 7, 89, 121, 57, -86, -215, -209, 9, 407,
  840, 1122, 1122, 840, 407, 9, -209, -215, -86, 57, 121, 89, 7, -57,
  -67, -30, 17, 40, 31, 4, -18, -21, -10, 4, 11, 8, 1, -4,
  -5, -3, 1, 3};

//  // LPF FIR Filter Coefficients MFILT = 60, Fc = 70
//  const int HFXPT = 4096, MFILT = 60;
//  int h[] = {1, 3, 4, 3, -1, -6, -9, -8, -1, 11, 21, 21, 8, -16,
//  -39, -46, -26, 17, 66, 91, 68, -7, -106, -179, -170, -43, 196, 495,
//  768, 932, 932, 768, 495, 196, -43, -170, -179, -106, -7, 68, 91, 66,
//  17, -26, -46, -39, -16, 8, 21, 21, 11, -1, -8, -9, -6, -1,
//  3, 4, 3, 1};


 
  int i;
  const float INV_HFXPT = 1.0/HFXPT;
  static long xN[MFILT] = {inputX};
  long yOutput = 0;

  //
  // Right shift old xN values. Assign new inputX to xN[0];
  //
  for ( i = (MFILT-1); i > 0; i-- )
  {
    xN[i] = xN[i-1];
  }
   xN[0] = inputX;
 
  //
  // Convolve the input sequence with the impulse response
  //
 
  for ( i = 0; i < MFILT; i++)
  {
   
    // Explicitly cast the impulse value and the input value to LONGs then multiply
    // by the input value.  Sum up the output values
   
    yOutput = yOutput + long(h[i]) * long( xN[i] );
  }

  //  Return the output, but scale by 1/HFXPT to keep the gain to 1
  //  Then cast back to an integer
  //

  // Skip the first MFILT  samples to avoid the transient at the beginning due to end effects
  if (sampleNumber < MFILT ){
    return long(0);
  }else{
    return long(float(yOutput) * INV_HFXPT);
  }
}
