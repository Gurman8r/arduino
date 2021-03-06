/* SegmentConfig.h
*	Author: 	Melody Gurman
* 	Modified: 	11/11/2018
* * * * * * * * * * * * * * * */
#ifndef _SEGMENT_CONFIG_H_
#define _SEGMENT_CONFIG_H_

enum Digit : unsigned
{
  D0, D1, D2, D3, D4, D5, D6, D7, D8, D9,
  DA, DB, DC, DD, DE, DF,
  DG, DH, DJ, DL, DN, Dn, Do, DP, Dr, DT, DU, Du, DY,
  DDec, DSpc, DDash, DEq, DUln,
  MAX_DIGIT
};

const uint8_t SegAlpha[Digit::MAX_DIGIT] =
{
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01100111, // 9
  0b01110111, // A
  0b01111100, // B
  0b00111001, // C
  0b01011110, // D
  0b01111001, // E
  0b01110001, // F
  0b00111101, // G
  0b01110110, // H
  0b00011110, // J
  0b00111000, // L
  0b00110111, // N
  0b01010100, // n
  0b01011100, // o
  0b01110011, // P
  0b01010000, // r
  0b01111000, // t
  0b00111110, // U
  0b00011100, // u
  0b01101110, // Y
  0b10000000, // '.'
  0b00000000, // ' '
  0b01000000, // '-'
  0b01001000, // '='
  0b00001000, // '_'
};

#endif