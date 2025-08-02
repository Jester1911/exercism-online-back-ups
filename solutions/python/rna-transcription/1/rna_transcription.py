def get_rna_complement(dna: str) -> str:
    complements = {'A': 'U', 'G': 'C', 'C': 'G', 'T': 'A'}
    return complements[dna]


def to_rna(dna_strand: str) -> str:
    rna_strand = []

    for nuc in dna_strand:
        rna_strand.append(get_rna_complement(nuc))

    s = ''.join(rna_strand)

    return s
