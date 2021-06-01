set size square
rgb(r,g,b) = int(r)*65536 + int(g)*256 + int(b)
set term gif \
    animate \
size 700, 700 \
    delay 50 
set output "em.gif"
do for [i=0:19] {
plot "emr.txt" using 1:2:(rgb($3,$4,$5)) index i lc rgb variable title sprintf("i = %d",i),"ellipse.txt" using 1:2:3:4 index i with ellipses title sprintf("i = %d",i)
}