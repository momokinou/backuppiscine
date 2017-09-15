cat ./truc.txt | grep -i "bauer" | grep -i "nicolas" | grep -v "nicolasbauer" | grep '\(([0-9]\{3\})\|[0-9]\{3\}\)[ -]\?[0-9]\{3\}[ -]\?[0-9]\{4\}' | cut -f 3
