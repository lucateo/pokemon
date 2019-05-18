  #!/bin/bash 
 
  
	links2 -dump http://www.serebii.net/attackdex-xy/other.shtml | colrm 1 15 | colrm 45 89 | head -n -11 | tail -n +14 | cut -d' ' -f 1-2 | column -t | sed 's/ /-/g'
	echo do you want to continue? # lo fermo per vedere se tutto va bene
    read n 
  links2 -dump http://www.serebii.net/attackdex-xy/other.shtml | colrm 1 15 | colrm 45 89 | head -n -11 | tail -n +14 | cut -d' ' -f 1-2 | column -t | sed 's/ /-/g' >> dataMoveName.txt
   links2 -dump http://www.serebii.net/attackdex-xy/other.shtml | colrm 1 15 | colrm 45 89 | head -n -11 | tail -n +14 |cut -d' ' -f 15-60 | sed 's/--/0/g' | column -t  | awk '{print $1}' >> dataMovePP.txt
   links2 -dump http://www.serebii.net/attackdex-xy/other.shtml | colrm 1 15 | colrm 45 89 | head -n -11 | tail -n +14 |cut -d' ' -f 15-60 | sed 's/--/0/g' | column -t  | awk '{print $2}' >> dataMovePower.txt
   links2 -dump http://www.serebii.net/attackdex-xy/other.shtml | colrm 1 15 | colrm 45 89 | head -n -11 | tail -n +14 |cut -d' ' -f 15-60 | sed 's/--/0/g' | column -t  | awk '{print $3}' >> dataMoveAcc.txt
