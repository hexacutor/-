set size square
set output "wave.jpg"
plot "wave.txt" using 1:2 lc rgb 'red', "other.txt" using 1:2 lc rgb 'blue'