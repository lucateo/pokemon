#!/bin/bash 
if [ $# -eq 0 ]
 then
 echo devi mettere il tipo di pokemon che vuoi scaricare
 else    
                                       
  links2 -dump http://www.serebii.net/pokedex-xy/$1.shtml | tail -n +13 |head -n -11 | colrm 1 27 | colrm 63 78 | colrm 12 34 | column -t # questo stampa tutto perfettamente
  echo do you want to continue? # lo fermo per vedere se tutto va bene
  links2 -dump http://www.serebii.net/attackdex-xy/physical.shtml | colrm 1 15 | colrm 45 89 | head -n -11 | tail -n +14
  read n
  
  links2 -dump http://www.serebii.net/pokedex-xy/$1.shtml | tail -n +13 |head -n -11 | colrm 1 27 | colrm 63 78 | colrm 12 34 | column -t | awk '{print $1}' >> pokname.txt
  links2 -dump http://www.serebii.net/pokedex-xy/$1.shtml | tail -n +13 |head -n -11 | colrm 1 27 | colrm 63 78 | colrm 12 34 | column -t | awk '{print $2}' >> pokps.txt
  links2 -dump http://www.serebii.net/pokedex-xy/$1.shtml | tail -n +13 |head -n -11 | colrm 1 27 | colrm 63 78 | colrm 12 34 | column -t | awk '{print $3}' >> pokatk.txt
  links2 -dump http://www.serebii.net/pokedex-xy/$1.shtml | tail -n +13 |head -n -11 | colrm 1 27 | colrm 63 78 | colrm 12 34 | column -t | awk '{print $4}' >> pokdef.txt
  links2 -dump http://www.serebii.net/pokedex-xy/$1.shtml | tail -n +13 |head -n -11 | colrm 1 27 | colrm 63 78 | colrm 12 34 | column -t | awk '{print $5}' >> pokspatk.txt
  links2 -dump http://www.serebii.net/pokedex-xy/$1.shtml | tail -n +13 |head -n -11 | colrm 1 27 | colrm 63 78 | colrm 12 34 | column -t | awk '{print $6}' >> pokspdef.txt
  links2 -dump http://www.serebii.net/pokedex-xy/$1.shtml | tail -n +13 |head -n -11 | colrm 1 27 | colrm 63 78 | colrm 12 34 | column -t | awk '{print $7}' >> pokspeed.txt

  
fi
