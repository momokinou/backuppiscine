ldapsearch -Q uid=z'*' | sort -r -f | grep ^'cn: ' | cut -c5-
