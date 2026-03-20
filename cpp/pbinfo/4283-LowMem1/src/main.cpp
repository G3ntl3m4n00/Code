#include <fstream>
#include <vector>

// Gyors integer beolvasó
inline long long
readInt (std::ifstream &f)
{
    long long x = 0;
    int c;
    bool neg = false;
    while ((c = f.get ()) < '0' && c != '-' && c != EOF)
        ;
    if (c == '-')
        {
            neg = true;
            c = f.get ();
        }
    else if (c == EOF)
        return 0;
    do
        {
            x = x * 10 + (c - '0');
        }
    while ((c = f.get ()) >= '0');
    return neg ? -x : x;
}

int
main ()
{
    std::ifstream fin ("lowmem1.in");
    std::ofstream fout ("lowmem1.out");

    int k = (int)readInt (fin);

    std::vector<long long> buf (k);
    long long current_sum = 0;

    for (int i = 0; i < k; i++)
        {
            buf[i] = readInt (fin);
            current_sum += buf[i];
        }

    long long max_sum = current_sum;
    int best_start = 0;
    int pos = 0;
    int idx = k;

    long long x;
    while (fin.peek () != EOF)
        {
            // skip whitespace/newline
            int c = fin.peek ();
            if (c == ' ' || c == '\n' || c == '\r')
                {
                    fin.get ();
                    continue;
                }
            if (c == EOF)
                break;

            x = readInt (fin);
            current_sum += x - buf[pos];
            buf[pos] = x;
            pos = (pos + 1) % k;

            if (current_sum > max_sum)
                {
                    max_sum = current_sum;
                    best_start = idx - k + 1;
                }
            idx++;
        }

    // Fájl újraolvasása a legjobb szekvenciához
    fin.close ();
    fin.open ("lowmem1.in");
    readInt (fin); // k kihagyása

    for (int i = 0; i < best_start; i++)
        readInt (fin);

    fout << max_sum << "\n";
    for (int i = 0; i < k; i++)
        {
            if (i > 0)
                fout << " ";
            fout << readInt (fin);
        }
    fout << "\n";

    return 0;
}
