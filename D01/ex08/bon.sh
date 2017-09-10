ldapsearch -Q | grep "cn: " | cut -d " " -f3 | grep -i bon | wc -l
