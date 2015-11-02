trap myintfun INT
function myintfun()
{
	echo "Got SIGINT,exting..."
	exit
}
for ((i=$1;i<$2;i++))
do 
	{
		ping -t 1 -c 1 192.168.0.$i >/dev/null
		if [ $? -eq 0 ];
		then
		       	echo "192.168.0.$i is alive"
		else
			echo "192.168.0.$i is not alive"
		fi
	}
done
