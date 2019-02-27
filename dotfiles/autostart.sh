# $HOME/.dwm/autostart.sh
# This file is executed by dwm upon startup

sudo ethtool -s enp2s0f5 autoneg off duplex full speed 100 &
$HOME/.fehbg &
compton --conf $HOME/.config/compton.conf -b &
amixer set Master 100% &

updates(){
	list="$(pacman -Sup)"

	if [ "$list" == "" ]; then
    		count=0
	else
    		count=`echo "$list" | wc -l`
	fi

	echo " $count"
}

datetime(){
	datetime=`date +\ %A\ %B\ %Y\ \|\ \\ %H\:%M`
	echo "$datetime"
}

while true; do
	xsetroot -name " $(updates) | $(datetime) | Kai"
	sleep 1m
done
