cat /etc/passwd | grep -v "#" | grep . | cut -d ':' -f 1 | rev | sort -r | grep "$FT_LINE1" | grep "$FT_LINE2" | tr "\n" ", " | rev | sed s/,/./ | cut -c2- | rev | tr - "\n" | sed 's/,,*$/ /'
