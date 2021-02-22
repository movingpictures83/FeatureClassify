# FeatureClassify
# Language: C++
# Input: TXT
# Output: QZA
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: Qiime 2 2020.11, Conda 4.9.2

Qiime2 feature classifier (Bolyen et al, 2019).

The plugin accepts as input a TXT file of tab-delimited keyword-value pairs:
classifier: Classifier to use (i.e. SILVA)
reads: Input sequences

Output clusters and taxa will be in QZA format.

