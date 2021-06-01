set size square
set term jpeg
set output "tree.jpg"
plot "tree.txt" using 1:2 with lines