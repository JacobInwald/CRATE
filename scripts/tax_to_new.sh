
tax_dir="data/taxonomy"
new_dir="data/new_dataset"

for filename in $tax_dir/*/
do
    tax=$(basename $filename)
    echo "Processing $tax"
    mkdir -p $new_dir/$tax
    cp $tax_dir/$tax/manifest.sarif $new_dir/$tax/manifest.sarif
    cp $tax_dir/$tax/src/* $new_dir/$tax/

done