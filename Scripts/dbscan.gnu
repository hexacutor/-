set size square
set term jpeg
set output "dbscan.jpg"
rgb(r,g,b) = int(r)*65536 + int(g)*256 + int(b)
plot "dbspr.txt" using 1:2:(rgb($3,$4,$5)) lc rgb variable