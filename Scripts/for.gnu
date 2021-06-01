set size square
set yrange [-0.8:0.8]
set xrange [-0.8:0.8]
rgb(r,g,b) = int(r)*65536 + int(g)*256 + int(b)
set term gif \
    animate \
size 700, 700 \
    delay 150 
set output "forel.gif"
do for [i=0:3] {
plot "forel.txt" using 1:2:(rgb($3,$4,$5)) index i lc rgb variable ,"forelc.txt" using 1:2:6:(rgb($3,$4,$5)) index i with circles lc rgb variable
pause 1
plot "forel.txt" using 1:2:(rgb($3,$4,$5)) index i lc rgb variable ,"forelc.txt" using 1:2:6:(rgb($3,$4,$5)) index i with circles lc rgb variable,"forelc.txt" using 1:2:(rgb($3,$4,$5)) index i pt 7
pause 1
plot "forelc.txt" using 1:2:(rgb($3,$4,$5)) index i pt 7 title sprintf("New elements i = %d",i)            
}