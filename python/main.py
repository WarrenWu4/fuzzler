from algos.levenshtein_distance import levenshtein_distance

def main():
    s1 = "begin"
    s2 = "aegn"
    dist = levenshtein_distance(s1, s2)
    print(dist)

if __name__ == "__main__":
    main()
