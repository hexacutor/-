set size square
set term jpeg
set output "voron.jpg"
plot "voron.txt" using 1:2 with lines, "field.txt","tri.txt" using 1:2 with lines
