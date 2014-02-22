dir="pushswap"
mkdir $dir

git clone vogsphere@vogsphere.42.fr:algo-1-001/2013/par-1-1/pushswap/$1 $dir/$1
git clone vogsphere@vogsphere.42.fr:algo-1-001/2013/par-1-1/pushswap/$2 $dir/$2
git clone vogsphere@vogsphere.42.fr:algo-1-001/2013/par-1-1/pushswap/$3 $dir/$3
git clone vogsphere@vogsphere.42.fr:algo-1-001/2013/par-1-1/pushswap/$4 $dir/$4
git clone vogsphere@vogsphere.42.fr:algo-1-001/2013/par-1-1/pushswap/$5 $dir/$5
git clone vogsphere@vogsphere.42.fr:algo-1-001/2013/par-1-1/pushswap/$6 $dir/$6

echo "\nGet number and clone ...\n"
touch $dir/num
echo "$1" > $dir/num
ldapsearch -Q uid=$1 | grep mobile-phone >> $dir/num
echo "$2" >> $dir/num
ldapsearch -Q uid=$2 | grep mobile-phone >> $dir/num
echo "$3" >> $dir/num
ldapsearch -Q uid=$3 | grep mobile-phone >> $dir/num
echo "$4" >> $dir/num
ldapsearch -Q uid=$4 | grep mobile-phone >> $dir/num
echo "$5" >> $dir/num
ldapsearch -Q uid=$5 | grep mobile-phone >> $dir/num
echo "$6" >> $dir/num
ldapsearch -Q uid=$6 | grep mobile-phone >> $dir/num

echo "Sending mail to $1 ..."
./mail.sh $1
echo "Sending mail to $2 ..."
./mail.sh $2
echo "Sending mail to $3 ..."
./mail.sh $3
echo "Sending mail to $4 ..."
./mail.sh $4
echo "Sending mail to $5 ..."
./mail.sh $5
echo "Sending mail to $6 ...\n"
./mail.sh $6

cat $dir/num
