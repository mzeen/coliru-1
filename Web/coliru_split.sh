mv main.cpp input
while IFS= read line ; do 
    { [ "$(echo $line | grep '\#pragma coliru' | wc -l)" == "1" ] \
        && export FILE="$(echo $line | perl -pe 's,.*\"(.*)\".*,\1,')" \
        && { [ ! -f $FILE ] || { echo "$FILE already exists" 2>&1 && exit 1 ; } } \
        && touch $FILE ; } || printf "$line\n" >> $FILE
done < input
rm input
