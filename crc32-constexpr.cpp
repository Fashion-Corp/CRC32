// #Hashing #CRC32 This is an implementation of CRC32, which is fully recursive and constexpr compliant, that is - it can be determined
// at compile time. Thereby you can create constants, which are determined at compile time and thereby you can use these
// constants for instance in switch/case constructions. These 6 lines of code down under here, have come by with a lot of sweat. I guess that
// is the deal for all compact, efficient code.
// 
// You are free to use it under the GNU public license version 3.0, and no royalties of any kind are due to me, and I contribute this to everyone on Earth.
//
// If you, for instance, have some strings being passed as commands from a server to your IOT device, as in the example here below, then
// the use of the crc32c() algorithm makes it possible to create constants of where to go, so when a call comes, you can hash the incoming
// text, and you will get the hashed value, which you can then use to switch on. Here a coding example form my practice:
//
// Please let this (C) note remain so that if anyone have trouble with the code, they know where to find me:
//
// David T. Svarrer, April 2023, E: david.t.svarrer@gmail.com, T:+4536991379, M:+254711405732, Zello:choop1, Signal:david.t.svarrer
//
// constexpr uint32_t todaysDayNumberSet          = crc32c("todaysDayNumber");
// constexpr uint32_t todaysYearNumberSet         = crc32c("todaysYearNumber");
// constexpr uint32_t homeSsidSet                 = crc32c("homeSsidSet");
// constexpr uint32_t homeSsidPasswordSet         = crc32c("homeSsidPasswordSet");
// constexpr uint32_t skyFiSsidSet                = crc32c("skyfiSsidSet");
// constexpr uint32_t skyFiSsidPasswordSet        = crc32c("skyfiSsidPasswordSet");  
//
// void takeAction (char *command) {
//   switch (crc32c (command)) {
//     case todaysDayNumberSet:
//       // do your thing
//       break;
//     case todaysYearNumberSet:
//       // do your thing
//       break;
//     case homeSsidSet:
//       // do your thing
//       break;
//     case homeSsidPasswordSet:
//       // do your thing
//       break;
//     case skyFiSsidSet:
//       // do your thing
//       break;
//     case skyFiSsidPasswordSet:
//       // do your thing
//       break;
//   }
// }

constexpr uint32_t crcSelf (const uint32_t crc) {
  return (crc >> 1) ^ ((crc & 1) * 0xEDB88320);
}

constexpr uint32_t crc32c (const char *data, int level = 0, uint32_t crc = 0xFFFFFFFF) { 
  return ((*data != '\0') ? crc32c (data+1, level+1, crcSelf(crcSelf(crcSelf(crcSelf(crcSelf(crcSelf(crcSelf(crcSelf(crc ^ *data))))))))) :  crc ^ 0xFFFFFFFF) ;
}
