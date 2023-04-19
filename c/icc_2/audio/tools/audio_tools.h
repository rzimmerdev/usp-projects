#ifndef AUDIO_AUDIO_TOOLS_H
#define AUDIO_AUDIO_TOOLS_H

// Function to return array of coefficients from fourier transformation based on input .wav data,
// respective to each timestamp on .wav array
double complex *discrete_fourier_transform(unsigned char *wav, int size);

// Calculates euclidean distance of double complex coefficient
double component_magnitude(double complex coefficient);

// Returns array of complex values, referent to original values obtained with fourier transform,
// based on input array of complex fourier transformed coefficients
double complex *inverse_fourier_transform(double complex *coefficients, int size);

#endif
