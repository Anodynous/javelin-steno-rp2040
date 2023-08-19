//---------------------------------------------------------------------------

#pragma once
#include <stdint.h>
#include <stdlib.h>

//---------------------------------------------------------------------------

struct StenoConfigBlock;
struct StenoOrthography;
struct StenoDictionaryCollection;

//---------------------------------------------------------------------------

#define JAVELIN_USE_EMBEDDED_STENO 0
#define JAVELIN_USE_USER_DICTIONARY 1
#define JAVELIN_USB_MILLIAMPS 500

#define JAVELIN_SPLIT 1
#define JAVELIN_SPLIT_TX_PIN 2
#define JAVELIN_SPLIT_RX_PIN 2
#define JAVELIN_SPLIT_IS_MASTER 0
#define JAVELIN_SPLIT_IS_LEFT 0


constexpr uint8_t LEFT_COLUMN_PINS[] = {0, 8, 29, 28, 27, 26, 9};
constexpr uint32_t LEFT_COLUMN_PIN_MASK = 0x3C000301;
constexpr uint8_t LEFT_ROW_PINS[] = {4, 5, 6, 7, 3};
constexpr uint32_t LEFT_ROW_PIN_MASK = 0xf8;

constexpr uint8_t RIGHT_COLUMN_PINS[] = {9, 26, 27, 28, 29, 8, 0};
constexpr uint32_t RIGHT_COLUMN_PIN_MASK = 0x3C000301;
constexpr uint8_t RIGHT_ROW_PINS[] = {4, 5, 6, 7, 3};
constexpr uint32_t RIGHT_ROW_PIN_MASK = 0xf8;
// clang-format off

//
// Button indexes
//  0    1   2   3   4   5  |   6   7   8   9   10  11
//  12  13  14  15  16  17  |   18  19  20  21  22  23
//  24  25  26  27  28  29  |   30  31  32  33  34  35
//          36  37  38  39  |   40  41  42  43
//  44  45  46  47  48      |       49  50  51  52  53
//

constexpr int8_t LEFT_KEY_MAP[5][7] = {
  {  0,  1,  2,  3,  4,  5,  -1 },
  {  12, 13, 14, 15, 16, 17, -1 },
  {  24, 25, 26, 27, 28, 29, -1 },
  {  -1, -1, 36, 37, 38, 39, -1 },
  {  44, 45, 46, 47, 48, -1, -1 },
};

constexpr int8_t RIGHT_KEY_MAP[5][7] = {
  {  -1, 6,  7,  8,  9,  10, 11 },
  {  -1, 18, 19, 20, 21, 22, 23 },
  {  -1, 30, 31, 32, 33, 34, 35 },
  {  -1, 40, 41, 42, 43, -1, -1 },
  {  -1, 49, 50, 51, 52, 53, -1 },
};

// clang-format on

const StenoConfigBlock *const STENO_CONFIG_BLOCK_ADDRESS =
    (const StenoConfigBlock *)0x10040000;
const uint8_t *const BUTTON_MANAGER_BYTE_CODE = (const uint8_t *)0x10040100;
const StenoOrthography *const ORTHOGRAPHY_ADDRESS =
    (const StenoOrthography *)0x10042000;
const uint8_t *const STENO_WORD_LIST_ADDRESS = (const uint8_t *)0x10044000;
const StenoDictionaryCollection *const STENO_MAP_DICTIONARY_COLLECTION_ADDRESS =
    (const StenoDictionaryCollection *)0x10400000;
const uint8_t *const STENO_USER_DICTIONARY_ADDRESS =
    (const uint8_t *)0x10fc0000;
const size_t STENO_USER_DICTIONARY_SIZE = 0x40000;

const size_t MAXIMUM_MAP_DICTIONARY_SIZE = 0xbc0000;
const size_t MAXIMUM_BUTTON_SCRIPT_SIZE = 0x1f00;
const size_t BUTTON_COUNT = 54;

const char *const MANUFACTURER_NAME = "anodyne";
const char *const PRODUCT_NAME = "Baltazar (Javelin)";
const int VENDOR_ID = 0x8d1d;
// const int PRODUCT_ID = 0xcf44;

//---------------------------------------------------------------------------