// ///////////////////////
// //                   //
// //  File Attributes  //
// //                   //
// ///////////////////////

// Filename: baba_background.png
// Pixel Width: 160px
// Pixel Height: 144px

// /////////////////
// //             //
// //  Constants  //
// //             //
// /////////////////

const int baba_background_tile_map_size = 0x0168;
const int baba_background_tile_map_width = 0x14;
const int baba_background_tile_map_height = 0x12;

const int baba_background_tile_data_size = 0x0E50;
const int baba_background_tile_count = 0xE5;

// ////////////////
// //            //
// //  Map Data  //
// //            //
// ////////////////

const unsigned char baba_background_map_data[] ={
  0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,
  0x0C,0x0D,0x0E,0x00,0x00,0x00,0x00,0x00,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x14,
  0x14,0x14,0x16,0x17,0x14,0x18,0x19,0x00,0x00,0x00,0x00,0x1A,0x1B,0x1C,0x1D,0x1E,
  0x1F,0x20,0x14,0x14,0x14,0x14,0x14,0x21,0x22,0x23,0x24,0x00,0x00,0x00,0x25,0x26,
  0x27,0x28,0x29,0x2A,0x2B,0x14,0x2C,0x14,0x14,0x14,0x2D,0x2E,0x2F,0x30,0x31,0x00,
  0x00,0x00,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x14,0x14,0x14,0x14,0x14,0x3A,
  0x3B,0x3C,0x3D,0x00,0x00,0x00,0x3E,0x3F,0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x14,
  0x47,0x48,0x14,0x14,0x14,0x49,0x4A,0x4B,0x00,0x00,0x4C,0x4D,0x4E,0x4F,0x50,0x51,
  0x52,0x53,0x54,0x55,0x56,0x57,0x14,0x14,0x14,0x14,0x58,0x59,0x00,0x00,0x5A,0x5B,
  0x5C,0x5D,0x5E,0x5F,0x60,0x61,0x62,0x63,0x64,0x65,0x14,0x14,0x14,0x14,0x66,0x67,
  0x00,0x00,0x00,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,0x70,0x71,0x72,0x14,0x14,
  0x14,0x14,0x73,0x74,0x00,0x00,0x00,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,
  0x7E,0x7F,0x80,0x14,0x14,0x14,0x81,0x82,0x00,0x00,0x00,0x83,0x84,0x85,0x86,0x87,
  0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x14,0x14,0x14,0x8F,0x90,0x00,0x00,0x00,0x91,
  0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x14,0x14,0x9F,
  0x00,0x00,0x00,0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0x14,
  0xAC,0xAD,0x14,0xAE,0x00,0x00,0x00,0x00,0xAF,0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,
  0xB7,0xB8,0x85,0x14,0xB9,0xBA,0x14,0xBB,0x00,0x00,0x00,0x00,0xBC,0xBD,0xBE,0xBF,
  0xC0,0xC1,0xC2,0xC3,0xC4,0x14,0x85,0x14,0xC5,0xC6,0xC7,0x14,0x00,0x00,0x00,0x00,
  0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,0x14,0x14,0xD0,0x14,0xD1,0xD2,0xD3,0x14,
  0x00,0x00,0x00,0x00,0x00,0xD4,0xD5,0x14,0xD6,0xD7,0xD8,0x14,0x14,0x14,0xD9,0x14,
  0x14,0xDA,0xDB,0xDC,0x00,0x00,0x00,0x00,0x00,0xDD,0xDE,0xDF,0xE0,0xE1,0x14,0x14,
  0x14,0x14,0x14,0x14,0x14,0xE2,0xE3,0xE4
};

// /////////////////
// //             //
// //  Tile Data  //
// //             //
// /////////////////

const unsigned char baba_background_tile_data[] ={
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFC,0xFF,0xF8,0xFF,0xE0,0xFF,0xC0,0xFF,0x80,0xFF,0x00,0xFF,
  0xC0,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFC,0x00,0xE0,0x00,0x80,
  0x00,0xFE,0x00,0xFE,0x00,0xE0,0x00,0xC0,0x00,0xC0,0x43,0x43,0x04,0x07,0x18,0x1F,
  0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x3C,0x3F,0xC0,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0x00,0x01,0x01,0x3E,0x3F,0xE0,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xF1,
  0x00,0x00,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFC,0x00,0xF8,0x00,0xF8,0x00,0xF8,
  0x7F,0x7F,0xF8,0x87,0x00,0xFF,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,
  0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xE0,0xC0,0x3E,0xFE,0x01,0xFF,0x00,0x3F,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0xF8,0xF8,0x0F,0xFF,0x00,0xFF,0x00,0x7F,0x00,0x3F,0x00,0x1F,
  0x00,0x7F,0x00,0x3F,0x00,0x0F,0x00,0x40,0xC0,0xE0,0x30,0xF0,0x0E,0xFE,0x01,0xFF,
  0x3F,0xFF,0x0F,0xFF,0x03,0xFF,0x01,0x7F,0x00,0x3F,0x00,0x3F,0x00,0x1F,0x00,0x07,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0x3F,0xFF,0x1F,0xFF,0x0F,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0xFF,0xC0,0xFF,
  0xFC,0xFF,0xF8,0xFF,0xF0,0xFF,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0xFC,0x00,0xFC,0x00,0xFC,0x00,0xF0,0x00,0xE0,0x00,0xE0,0x03,0xC3,0x06,0x85,
  0x00,0x00,0x01,0x01,0x07,0x06,0x0C,0x0B,0x30,0x3F,0xC0,0xFF,0x80,0x7F,0x00,0xFF,
  0x60,0x7F,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0xF1,0x00,0xF1,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0xE0,0x00,0xF0,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0x1F,0x00,0x1F,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x80,0x87,0x40,0xC3,0x30,0xF1,0x10,0xF0,0x08,0xF8,0x08,0xF8,0x04,0xFC,0x04,0xFC,
  0x07,0xFF,0x07,0xFF,0x03,0xFF,0x03,0xFF,0x03,0xFF,0x03,0xFF,0x03,0xFF,0x03,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xFF,0xFC,0xFF,0xFC,0xFF,0xF8,0xFF,0xF0,0xFF,
  0x80,0xFF,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xF8,0x00,0xF8,0x00,0xF0,0x00,0xF0,
  0x00,0xFE,0x00,0xF8,0x00,0x80,0x00,0x00,0x01,0x01,0x02,0x03,0x0C,0x0F,0x78,0x7F,
  0x1C,0x1B,0x10,0x1F,0x20,0x3F,0xC0,0xFF,0x08,0xFF,0x06,0xFF,0x01,0xFF,0x00,0xFF,
  0x00,0xFF,0x1F,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x80,0xFF,0x60,0xFF,
  0x00,0xFF,0xF8,0xFF,0x07,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0xC0,0xFF,0x30,0xFF,0x0C,0xFF,0x02,0xFF,0x01,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x1F,0xFF,0xFF,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x04,0xFF,0xFD,0xFF,0xC7,0xFF,
  0x04,0xFC,0x04,0xFC,0x04,0xFC,0x08,0xFD,0x18,0xFF,0x30,0xF7,0xC0,0xEF,0x00,0x8F,
  0x03,0x7F,0x03,0xFF,0x03,0xFF,0x07,0xFF,0x07,0xFF,0x0F,0xFF,0x1F,0xFF,0x3F,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFC,0xFF,0xFC,0xFF,0xFC,0xFF,0xF8,0xFF,
  0xC0,0xFF,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFE,
  0x00,0xF0,0x03,0xF3,0x04,0x85,0x08,0x0F,0x08,0x0F,0x0F,0x0F,0x1C,0x9F,0x60,0x7F,
  0x90,0xBF,0x10,0xFE,0x00,0xFC,0x00,0xF8,0x00,0xF0,0x00,0xF0,0x00,0xF1,0x00,0xFF,
  0x00,0xFF,0x00,0x1F,0x01,0x1F,0x02,0x1F,0x04,0x7F,0x08,0xFF,0x38,0xF8,0x20,0xEF,
  0x58,0xFF,0xFC,0xFF,0x82,0xFF,0x01,0xFF,0x00,0x3F,0x00,0x1B,0x00,0x03,0x00,0x80,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x80,0xFF,0x40,0xFF,0x20,0xBF,0x10,0x9F,0x0C,0x0F,
  0x80,0xFF,0x40,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x03,0xFF,0x02,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFE,0x00,0xFC,0x00,0xFC,0x00,0xFC,0x00,0xFF,0x00,0xFF,
  0x03,0xFF,0x01,0xFF,0x00,0x07,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0xDF,0x01,0xFF,
  0x00,0x9F,0x00,0x9F,0x80,0x9F,0x81,0x9F,0x81,0x9F,0x81,0x9F,0x81,0x9F,0x00,0x0F,
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xE0,0xFF,0xE0,0xFF,0xE0,0xFF,0xE0,0xFF,0xE0,0xFF,
  0x00,0xFC,0x00,0xFC,0x00,0xFC,0x01,0xF9,0x01,0xF1,0x01,0xF1,0x01,0xE1,0x01,0xE1,
  0x40,0x7F,0x80,0xFF,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x20,0xFF,0x20,0xFF,0x40,0xFF,
  0x00,0xFF,0x00,0xFF,0x01,0xFF,0x02,0xFE,0x04,0xFC,0x08,0xF8,0x10,0xF0,0x50,0xF0,
  0x40,0xCF,0x80,0x80,0x00,0x0F,0x03,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0xE0,0x03,0x1F,0x00,0xCF,0xF0,0xF0,0x1C,0x7C,0x03,0x1F,0x00,0x07,0x00,0x00,
  0x02,0x0F,0xF1,0xF1,0x00,0xE0,0x07,0x07,0x18,0x1F,0xE0,0xFE,0x00,0xF0,0x03,0x03,
  0x00,0xFF,0x00,0xFF,0x80,0xFF,0xC0,0xFF,0x20,0x3F,0x10,0x1F,0x10,0x1F,0x1C,0x1F,
  0x00,0xFF,0x00,0xFF,0x01,0xFF,0x01,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x07,0xFF,0x78,0xFF,0xC0,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0x07,0x80,0x87,0x40,0xC7,0x40,0xD1,0x20,0xE1,0x10,0xF1,0x10,0xF1,0x08,0xF9,
  0x7F,0xFF,0x7F,0xFF,0x3F,0xFF,0x1F,0xFF,0x1F,0xFF,0x07,0xFF,0x03,0xFF,0x01,0xFF,
  0xE0,0xFF,0xE0,0xFF,0xE0,0xFF,0xE0,0xFF,0xE0,0xFF,0xE0,0xFF,0xE0,0xFF,0xE0,0xFF,
  0x00,0xE1,0x00,0xE0,0x00,0xF0,0x00,0xF0,0x01,0xE1,0x01,0xE1,0x01,0xE1,0x01,0xE1,
  0xC0,0xFF,0x80,0xFF,0x83,0xFF,0x9F,0xFF,0xBF,0xFF,0x33,0xFF,0x06,0xFF,0x04,0xFE,
  0xA1,0xE0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC7,0xFF,0xEB,0xFF,0xCB,0xCF,
  0xE0,0xE0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x00,0x00,0x84,0x84,0xE5,0xE5,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x04,0x04,0x04,0x04,0x1F,0x0F,0x1F,0x1F,0x9F,0x8F,0x0F,0x0F,0x0F,0x0F,0x07,0x1F,
  0x7E,0x7F,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFC,0xFF,0xFC,0xFF,0xF1,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0xC0,0xFF,0x60,0xFF,0x20,0xFF,0xF0,0xFF,0xF0,0xFF,
  0x00,0xE3,0x00,0xE3,0x00,0xE1,0x00,0xE0,0x00,0xF0,0x00,0xF8,0x00,0xF8,0x00,0xF8,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0x7F,0x00,0x7F,0x00,0x3F,0x00,0x1F,
  0x08,0xF8,0x04,0xFC,0x04,0xFC,0x02,0xFE,0x02,0xFE,0x01,0xFF,0x01,0xFF,0x00,0xFF,
  0x00,0x7F,0x00,0x7F,0x00,0x7F,0x40,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x07,0x80,0x87,
  0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0x3F,0xFF,0x3F,0xFF,0x3F,0xFF,0x3F,0xFF,0x3F,0xFF,
  0xE0,0xFF,0xE0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0xFF,
  0x01,0xE1,0x01,0xF1,0x01,0xF1,0x00,0xF0,0x00,0xF0,0x00,0xF8,0x00,0xF8,0x00,0xF8,
  0x05,0xFF,0x05,0xFF,0x8A,0xFE,0x8A,0xFE,0x8A,0xFE,0x41,0x7F,0x41,0x7F,0x41,0x5F,
  0x9C,0x9F,0x98,0x9F,0x98,0x9F,0x91,0x97,0x41,0x5F,0x41,0x5F,0x49,0x4F,0xC9,0xCF,
  0x09,0xFF,0x7E,0xFF,0xFF,0xFF,0xFF,0xFF,0xF3,0xF3,0xF3,0xF3,0xFF,0xFF,0xFF,0xFF,
  0x3F,0xFF,0x7E,0xFE,0x1C,0xFC,0xF4,0xFC,0xF4,0xFC,0xF4,0xFC,0xF4,0xFC,0xE4,0xFC,
  0x23,0x3B,0x21,0x21,0x21,0x21,0x21,0x21,0x20,0x21,0x40,0x40,0x40,0x40,0x40,0xC0,
  0xFF,0xFF,0xBF,0xFF,0x3F,0xFF,0x3C,0xFC,0x3C,0xFC,0xBF,0xFF,0x3F,0xFF,0x1F,0xFF,
  0xF8,0xFF,0xFC,0xFF,0xFF,0xFF,0xFD,0xFF,0xFD,0xFF,0xFD,0xFF,0xF8,0xFF,0xF0,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x80,0xFF,0x40,0xFF,0x20,0xBF,0x20,0xAF,
  0x00,0xFC,0x00,0xFE,0x00,0xFE,0x00,0xFF,0x04,0xFF,0x04,0xFF,0x02,0xFF,0x02,0xFF,
  0x00,0x1F,0x00,0x0F,0x00,0x0F,0x00,0x07,0x00,0x87,0x00,0xC3,0x00,0xC3,0x00,0xE3,
  0x80,0x87,0x40,0xC7,0x40,0xC7,0x40,0xC3,0x60,0xE3,0x20,0xE3,0x10,0xF7,0x10,0xF7,
  0x3F,0xFF,0x3F,0xFF,0x3F,0xFF,0x1F,0xFF,0x1F,0xFF,0x1F,0xFF,0x1F,0xFF,0x0F,0xFF,
  0xF8,0xFF,0xF8,0xFF,0xFC,0xFF,0xFC,0xFF,0xFC,0xFF,0xFC,0xFF,0xFE,0xFF,0xFE,0xFF,
  0x00,0xF8,0x00,0xF8,0x00,0xF8,0x00,0xFC,0x00,0xFE,0x00,0xFE,0x00,0xFF,0x00,0xFF,
  0x30,0x3F,0x18,0x1F,0x18,0x1F,0x14,0x1F,0x10,0x1F,0x10,0x1F,0x10,0x9F,0x10,0xDF,
  0xBC,0xBF,0xB0,0xBF,0xB0,0xBF,0xB0,0xB7,0x5F,0xDF,0x58,0xF8,0x36,0xF6,0x2F,0xFF,
  0xFF,0xFF,0x7F,0xFF,0x7E,0xFF,0x00,0xFF,0x01,0xFF,0x01,0x1D,0x0C,0x02,0x9C,0xDC,
  0x8C,0xFC,0x30,0xF9,0x31,0xF1,0x71,0xE7,0x40,0xF7,0x80,0xF7,0x00,0x00,0x00,0x00,
  0x80,0x80,0x80,0x80,0x00,0xC0,0x00,0x81,0x00,0x81,0x01,0x01,0x00,0x00,0x7F,0x7F,
  0x03,0xFF,0x00,0xFF,0x01,0x7F,0x8E,0xFF,0x30,0xFF,0x20,0xFF,0x00,0x00,0x00,0x00,
  0xE0,0xFF,0x01,0xFF,0x0F,0xEF,0x00,0x80,0x00,0x81,0x01,0x8F,0x00,0x3F,0x00,0x00,
  0x58,0xDF,0xD8,0xCF,0x04,0x07,0x3C,0x3F,0xE2,0xFF,0x02,0xF9,0x00,0xE1,0x01,0x00,
  0x01,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,
  0x00,0xE3,0x80,0xFF,0x40,0xFF,0x40,0xFF,0x20,0xFF,0x20,0xFF,0x20,0xFF,0x20,0xFF,
  0x10,0xF0,0x10,0xF0,0x08,0xF8,0x08,0xF8,0x08,0xF8,0x04,0xFC,0x04,0xFC,0x04,0xFC,
  0x0F,0xFF,0x0F,0xFF,0x0F,0xFF,0x1F,0x7F,0x0F,0x7F,0x0F,0x1F,0x0F,0x1F,0x0F,0x1F,
  0x00,0xFE,0x00,0xFE,0x80,0xFE,0x80,0xFF,0x80,0xFF,0xC0,0xFF,0xC0,0xFF,0xC0,0xFF,
  0x10,0x1F,0x10,0x1F,0x10,0x1F,0x10,0x1F,0x10,0x1F,0x10,0x1F,0x10,0x1F,0x10,0x1F,
  0x2C,0xFF,0x14,0xFF,0x14,0xFC,0x0C,0xFC,0x0C,0xFC,0x05,0xFC,0x03,0xFF,0x03,0xFF,
  0x39,0xF9,0x62,0xE3,0xC2,0x47,0xC4,0xC7,0x89,0x8F,0x88,0x9D,0x90,0x9C,0x10,0x18,
  0x00,0x00,0x00,0x80,0x00,0xE0,0x80,0x80,0x00,0x80,0x00,0x80,0x00,0x00,0x00,0x00,
  0x03,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x0F,0x0F,0x3D,0x3D,
  0x80,0x80,0xF0,0xF0,0xC8,0xF8,0xC6,0xFE,0x81,0xFF,0x00,0xFF,0x00,0xFF,0xFC,0xFF,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x80,0xBE,0x81,0x8F,0x40,0xC3,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,
  0x40,0x7F,0x20,0x3F,0x20,0x3F,0x10,0x1F,0x10,0x1F,0x08,0x0F,0x08,0x0F,0x0C,0x0F,
  0x10,0xFF,0x10,0xFF,0x08,0xFF,0x08,0xFF,0x04,0xFF,0x04,0xFF,0x04,0xFF,0x02,0xFF,
  0x04,0xFC,0x04,0xFC,0x04,0xFC,0x04,0xFC,0x0C,0xFC,0x08,0xF8,0x09,0xFD,0x08,0xF8,
  0x0F,0x3F,0x0F,0x3F,0x07,0x7F,0x07,0x7F,0x07,0x7F,0x07,0x7F,0x07,0xFF,0x03,0xFF,
  0xE0,0xFF,0xE0,0xFF,0xE0,0xFF,0xE0,0xFF,0xE0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,
  0x08,0x1F,0x08,0x1F,0x08,0x0F,0x04,0x2F,0x04,0xEF,0x04,0x8F,0x04,0x8F,0x02,0x8F,
  0x03,0xFF,0x03,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,
  0x00,0x18,0x00,0x38,0x00,0x38,0x20,0x38,0x00,0x18,0x00,0x01,0x00,0x01,0x00,0x01,
  0x03,0x03,0x06,0x06,0x1F,0x1F,0x36,0x36,0x78,0x78,0x69,0xE9,0xA9,0xE9,0xA9,0xE9,
  0xEE,0xEE,0x78,0x78,0x84,0x84,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x12,0x12,
  0x26,0x2F,0x25,0x27,0x24,0x25,0x24,0x27,0x24,0x24,0x24,0x24,0x24,0x24,0x22,0x22,
  0x40,0xC1,0x80,0xE0,0x80,0xF0,0xC0,0xF8,0xA0,0xFC,0xA0,0xFE,0xB0,0xFF,0xB0,0xFF,
  0x30,0xF8,0x10,0xF8,0x18,0xF8,0x38,0x78,0x04,0x3E,0x02,0x1E,0x03,0x1F,0x01,0x8F,
  0x0E,0x0F,0x0A,0x0F,0x0A,0x0F,0x09,0x0F,0x09,0x0F,0x08,0x0F,0x08,0x0F,0x08,0x0F,
  0x02,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x00,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x80,0xFF,0x80,0xFF,0x40,0xFF,0x40,0xFF,
  0x08,0xF8,0x08,0xF8,0x08,0xF8,0x08,0xF8,0x04,0xFC,0x04,0xFC,0x02,0xFE,0x02,0xFE,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0x3F,0x00,0x3F,0x00,0x00,0x00,0x00,
  0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,
  0x02,0x87,0x02,0x83,0x02,0x83,0x02,0x83,0x01,0xC3,0x01,0xF1,0x01,0xF1,0x01,0xE1,
  0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,
  0x01,0x01,0x02,0x03,0x02,0x03,0x02,0x0F,0x02,0x1F,0x06,0x1F,0x04,0x3F,0x0C,0x7F,
  0x29,0xE9,0x08,0xD8,0x68,0xE8,0x68,0xE8,0x28,0xE8,0x28,0xE8,0x28,0xE8,0x28,0xE8,
  0x12,0x12,0x92,0x92,0x92,0x92,0x93,0x93,0x93,0x93,0xB3,0xB3,0xF3,0xF3,0xB3,0xB3,
  0x22,0x22,0x22,0x22,0x22,0x22,0xE2,0xE2,0x32,0xF2,0x37,0xF7,0x37,0x3F,0x37,0x3F,
  0xA0,0xBB,0xA0,0xB9,0xA8,0xB8,0xA8,0xB8,0xA8,0xB8,0xA8,0xBC,0xA8,0xFC,0xE8,0xFC,
  0x00,0xCF,0x20,0xE7,0x00,0xE7,0x00,0x63,0x00,0x33,0x00,0x31,0x04,0x1C,0x00,0x08,
  0x88,0x8E,0x88,0xCE,0xC8,0xCE,0x48,0xCE,0x08,0xEE,0x08,0xEE,0x08,0xEE,0x08,0xEC,
  0x80,0xFF,0x40,0xFF,0x40,0xFF,0x40,0x7F,0x40,0x7F,0x40,0x7F,0x20,0x3F,0x20,0x3F,
  0x40,0xFF,0x20,0xFF,0x20,0xFF,0x20,0xFF,0x20,0xFF,0x10,0xFF,0x10,0xFF,0x08,0xFF,
  0x01,0xFF,0x01,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0x00,0xFF,0xFF,0xC0,0xFF,0xA0,0xFF,0x70,0xFF,0x4C,0xFF,0x42,0xFF,0x23,0xFF,
  0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF0,0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0xFF,
  0x00,0xE1,0x00,0xE1,0x00,0xF1,0x00,0xF1,0x00,0xF0,0x00,0xF8,0x00,0xF8,0x00,0xF8,
  0x81,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x40,0xFF,0x40,0x7F,
  0x18,0xFF,0x90,0xFF,0xE0,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x29,0xF9,0x39,0xF9,0x3D,0xFD,0x3D,0xFD,0x2D,0xEF,0x66,0xE7,0x66,0xE6,0xE6,0xE6,
  0xB3,0xB7,0xB3,0xBF,0xB3,0xBF,0xA7,0xBF,0xAD,0xBD,0x72,0xF2,0x22,0x22,0x22,0x22,
  0x35,0x3D,0x3D,0x3D,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x25,0x25,0x25,0x25,
  0x00,0x3A,0x10,0x11,0x10,0x11,0x38,0x11,0x70,0x30,0x70,0x30,0xA0,0x20,0xA0,0xA0,
  0x00,0x0C,0x00,0x06,0x00,0x04,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x00,0x00,0x00,
  0x08,0xEC,0x08,0x7C,0x08,0x0C,0x08,0x08,0x10,0x18,0x10,0x18,0x10,0x18,0x10,0x18,
  0x20,0x3F,0x20,0x3F,0x10,0x1F,0x10,0x1F,0x10,0x1F,0x10,0x1F,0x10,0x1F,0x10,0x1F,
  0x08,0xFF,0x08,0xFF,0x08,0xFF,0x04,0xFF,0x04,0xFF,0x04,0xFF,0x02,0xFF,0x02,0xFF,
  0x00,0xFF,0x08,0xFF,0x08,0xFF,0x04,0xFF,0x02,0xFF,0x02,0xFF,0x01,0xFF,0x00,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x80,0xFF,
  0x20,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,
  0xF8,0xFF,0xFC,0xFF,0xFC,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x00,0xF8,0x00,0xF8,0x00,0xF8,0x00,0xFC,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x40,0x7F,0x40,0x7F,0x20,0x7F,0x20,0x3F,0x20,0xBF,0x20,0x3F,0x10,0x1F,0x10,0x1F,
  0x01,0xFF,0x02,0xFF,0x02,0xFE,0x1F,0xFF,0x1B,0xFB,0x1C,0xF8,0x08,0xFC,0x0E,0xFC,
  0xC6,0xC6,0x46,0x46,0x46,0xC6,0xC2,0xC2,0xC2,0xC6,0xE6,0xE6,0x3F,0x3F,0x29,0x21,
  0x26,0x26,0x24,0x24,0x24,0x24,0x68,0x68,0x4A,0x48,0x0A,0x1A,0xFB,0xFE,0x07,0x07,
  0x25,0x25,0x25,0x25,0x25,0x25,0x2C,0x24,0x65,0x25,0x46,0x46,0x78,0x78,0xE0,0xE0,
  0xA4,0xA0,0xA0,0xA0,0x40,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x41,
  0x10,0x38,0x10,0x30,0x20,0x30,0x20,0x30,0x60,0x60,0xC0,0xC0,0x80,0xD0,0xB0,0xF0,
  0x20,0x3F,0x20,0x3F,0x20,0x3F,0x60,0x7F,0x40,0x7F,0x40,0x7F,0x40,0x7F,0x40,0x7F,
  0x02,0xFF,0x02,0xFF,0x02,0xFF,0x02,0xFF,0x02,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,
  0x80,0xFF,0x40,0xFF,0x40,0xFF,0x40,0xFF,0x40,0xFF,0x20,0xFF,0x20,0xFF,0x10,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x0F,
  0x10,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,
  0x00,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,
  0x08,0x0F,0x08,0x8F,0x04,0x87,0x05,0x87,0x05,0x87,0x02,0x83,0x06,0xC7,0x15,0xC7,
  0x1F,0xFF,0x71,0xFF,0x40,0xFF,0x80,0xFC,0x00,0xF0,0x00,0xE0,0x00,0xC0,0x00,0xC0,
  0x21,0x21,0xA0,0xA0,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x04,0x04,0x04,0x04,0x04,0x04,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x1C,0x1C,
  0x01,0x01,0x03,0x03,0x04,0x04,0x0C,0x0F,0x11,0x17,0xE2,0xEF,0x04,0x1F,0x08,0x7E,
  0x20,0xF0,0x40,0xF0,0x40,0xF0,0x80,0xE0,0x30,0xF8,0x20,0xB0,0x21,0x31,0x41,0x61,
  0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x00,0xFF,0x00,0xFF,
  0x10,0xFF,0x10,0xFF,0x08,0xFF,0x08,0xFF,0x04,0xFF,0x04,0xFF,0x04,0xFF,0x04,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xF1,
  0x08,0xFF,0x04,0xFF,0x04,0xFF,0x02,0xFF,0x02,0xFF,0x01,0xFF,0x01,0xFF,0x00,0xFF,
  0xC0,0xFF,0xC0,0xFF,0xC0,0xFF,0xC0,0xFF,0xC0,0xFF,0xC1,0xFF,0xE2,0xFF,0xE4,0xFF,
  0x1C,0xFF,0x0C,0xEF,0x1F,0xDF,0x64,0xE7,0x87,0xC7,0x0E,0xEF,0x0A,0xEB,0x11,0xF1,
  0x00,0x80,0x00,0x00,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0F,0x18,0x1F,0x30,0x3F,0x40,0x7F,
  0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFE,0xFF,0x1E,0xFF,0x07,0xFF,0x07,0xFF,
  0x01,0x01,0x0F,0x0F,0x78,0x78,0xC0,0xC0,0x00,0xC0,0x00,0xE3,0x00,0xFF,0x80,0xFF,
  0xE0,0xE0,0x00,0x01,0x00,0x07,0x01,0x0F,0x02,0x7F,0x04,0xFC,0x18,0xF8,0x20,0xE1,
  0x18,0xFC,0x21,0xF1,0xC2,0xC3,0x04,0x8E,0x08,0x18,0x10,0x30,0x21,0xE1,0xC1,0xC1,
  0x82,0xC3,0x04,0x87,0x18,0x1F,0x10,0x1F,0x20,0x3F,0xC0,0xFF,0x00,0xFF,0x00,0xFF,
  0x04,0xFF,0x04,0xFF,0x02,0xFF,0x02,0xFF,0x02,0xFF,0x02,0xFF,0x01,0xFF,0x01,0xFF,
  0x00,0xF1,0x00,0xF1,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF8,0x00,0xF8,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0x7F,0x00,0x3F,0x00,0x3F,0x00,0x1F,
  0xE0,0xFF,0xE0,0xFF,0xF0,0xFF,0xF8,0xFF,0xFC,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x19,0xF9,0x04,0xFC,0x00,0xFC,0x00,0xFC,0x00,0xFC,0x00,0xFC,0x00,0xFC,0x00,0xFF,
  0x81,0x81,0x7E,0xFF,0x18,0x1F,0x10,0x1F,0x10,0x1F,0x10,0x1F,0x08,0x9F,0x08,0xCF,
  0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x07,0xFF,0x03,0xFF,0x03,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0xF9,0xFF,0xFE,0xFF,0xFC,0xFF,0xFC,0xFE,0x7C,0xFE,0x7C,0xFE,0x7C,0xFC,0x7C,0xFC,
  0xC1,0xFF,0x02,0xFE,0x0C,0xFC,0x30,0x30,0x00,0x00,0x01,0x01,0x06,0x07,0x04,0x07,
  0x02,0x03,0x0C,0x0F,0x10,0x1F,0x60,0x7F,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x02,0xFF,0x02,0xFF,0x02,0xFF,0x02,0xFF,
  0x01,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0xFC,0x80,0xFC,0x80,0xFE,0x80,0xFE,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,
  0x00,0x0F,0x00,0x0F,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x00,
  0x80,0xFF,0x80,0xFF,0xC0,0xFF,0xC0,0xFF,0xC0,0xFF,0xE0,0xFF,0xE0,0xFF,0xF0,0xFF,
  0x04,0xC7,0x04,0xC7,0x04,0xC7,0x02,0xC3,0x02,0xC3,0x01,0xC1,0x01,0xF9,0x01,0xF9,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x01,0xFF,0x03,0xFF,0x07,0xFF,
  0x7C,0xFC,0x7C,0xFC,0x78,0xF8,0x71,0xF1,0xE1,0xE1,0xE2,0xE3,0xC4,0xC7,0xC8,0xCF,
  0x08,0x0F,0x30,0x3F,0x40,0x7F,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x02,0xFF,0x04,0xFF,0x04,0xFF,0x04,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x10,0xFF,
  0x40,0xFF,0x40,0xFF,0x40,0xFF,0x40,0xFF,0x40,0xFF,0x40,0xFF,0x40,0xFF,0x20,0xFF,
  0x00,0x80,0x00,0x80,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xE0,0x00,0xE0,0x00,0xE0,
  0x00,0xFF,0x00,0xFF,0x00,0x7F,0x00,0x7F,0x00,0x3F,0x00,0x1F,0x00,0x1F,0x00,0x1F,
  0xF0,0xFF,0xF8,0xFF,0xF8,0xFF,0xFC,0xFF,0xFC,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,
  0x00,0xF8,0x00,0xF8,0x00,0xF8,0x00,0xF8,0x00,0xF8,0x00,0xFE,0x00,0xFE,0x00,0xFE,
  0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x40,0x7F,0x41,0x7F,0x43,0x7F,0x4C,0x7C,
  0x1F,0xFF,0x1E,0xFE,0x38,0xF8,0x70,0xF0,0xC3,0xC3,0x82,0x87,0x04,0x07,0x08,0x0F,
  0x30,0x3F,0x20,0x3F,0x40,0x7F,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x20,0xFF,0x20,0xFF,0x20,0xFF,0x20,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,
  0x00,0xE0,0x00,0xE0,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF8,
  0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x07,0x00,0x03,0x00,0x03,0x00,0x03
};
