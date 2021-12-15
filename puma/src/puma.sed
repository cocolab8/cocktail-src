s/!!~*$/WriteNl (f);/
s/!\([^!]*\)!~*$/WriteS (f, "\1"); WriteNl (f);/
s/!\([^!]*\)!/WriteS (f, "\1");/g
s/@\([^@]*\)@~*$/WriteS (f, '\1'); WriteNl (f);/
s/@\([^@]*\)@/WriteS (f, '\1');/g
