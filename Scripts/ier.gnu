set size square
set pointsize 1.5
rgb(r,g,b) = int(r)*65536 + int(g)*256 + int(b)
set term gif \
    animate \
size 700, 700 \
    delay 100 
set output "ier.gif"
do for [i=0:18] {
plot "ier.txt" using 1:($6 == 0 ? $2 : 1/0):(rgb($3,$4,$5)) index i lc rgb variable pt 7 title sprintf("Static i = %d",i),"ier.txt" using 1:($6 == 1 ? $2 : 1/0):(rgb($3,$4,$5)) index i lc rgb variable pt 5 title sprintf("New Cluster i = %d",i)
}