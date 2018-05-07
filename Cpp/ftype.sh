var=$(ls -l hello.txt)
echo $var
echo ${var:0:1}
ans=${var:0:1}
one="-"
two="d"
if [ "$ans" == "$one" ];
then 
echo "normal file";
elif [ "$ans" == "$two" ];
then
echo "directory file";
else
echo "link file";
fi 
