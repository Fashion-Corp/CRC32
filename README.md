# CRC32

This is a constexpr standard C++ implementation of CRC32, by making it recursive with a helper algorithm. Thereby you can use it to create switch/case on crc32(string). Very useful for IOT

I needed a C++ standard library implementation of CRC32, which could be calculated, compile time. I have spent considerable time on developing, a constexp compilable version so that you can use it instead of the very flawful typical implementation hash_string() - which is very inaccurate and often produces duplicates with even vastly different strings as input. This one here is tested against the original CRC32, and produces identical results. Creative Commons as license. 

Please provide the code with (C) David Svarrer, plus contacts: david.t.svarrer@gmail.com, and phone number +45 36 99 13 79 and mobile  +254 711 405 732, Signal: david.t.svarrer, and ZELLO: choop1


