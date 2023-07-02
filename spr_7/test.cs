using System;
using System.Collections.Generic;

namespace MisjonarzeIKanibale
{
    class Program
    {
        // Struktura reprezentująca stan misjonarzy i kanibali na brzegu
        struct Stan
        {
            public int misjonarzeLewa;
            public int kanibaleLewa;
            public bool statekNaLewymBrzegu;

            public Stan(int misjonarzeLewa, int kanibaleLewa, bool statekNaLewymBrzegu)
            {
                this.misjonarzeLewa = misjonarzeLewa;
                this.kanibaleLewa = kanibaleLewa;
                this.statekNaLewymBrzegu = statekNaLewymBrzegu;
            }
        }

        // Sprawdza, czy dany stan jest bezpieczny (nie narusza zasad gry)
        static bool CzyStanBezpieczny(Stan stan)
        {
            if (stan.misjonarzeLewa < 0 || stan.kanibaleLewa < 0) // Nie możemy mieć ujemnej liczby misjonarzy lub kanibali
                return false;

            if (stan.misjonarzeLewa > 3 || stan.kanibaleLewa > 3) // Nie możemy mieć więcej niż 3 misjonarzy lub kanibali
                return false;

            if (stan.misjonarzeLewa != 0 && stan.misjonarzeLewa < stan.kanibaleLewa) // Jeśli są misjonarze na lewym brzegu, liczba misjonarzy nie może być mniejsza niż liczba kanibali
                return false;

            if (3 - stan.misjonarzeLewa != 0 && (3 - stan.misjonarzeLewa) < (3 - stan.kanibaleLewa)) // Jeśli są misjonarze na prawym brzegu, liczba misjonarzy nie może być mniejsza niż liczba kanibali
                return false;

            return true;
        }

        // Sprawdza, czy dany stan jest celem (wszyscy misjonarze i kanibale na prawym brzegu)
        static bool CzyStanCelem(Stan stan)
        {
            return stan.misjonarzeLewa == 0 && stan.kanibaleLewa == 0 && !stan.statekNaLewymBrzegu;
        }

        // Wykonuje ruch - przemieszcza misjonarzy i kanibali na łódce na przeciwny brzeg
        static Stan WykonajRuch(Stan stan, int liczbaMisjonarzy, int liczbaKanibali)
        {
            if (stan.statekNaLewymBrzegu)
            {
                return new Stan(stan.misjonarzeLewa - liczbaMisjonarzy, stan.kanibaleLewa - liczbaKanibali, false);
            }
            else
            {
                return new Stan(stan.misjonarzeLewa + liczbaMisjonarzy, stan.kanibaleLewa + liczbaKanibali, true);
            }
        }

        // Sprawdza, czy dany stan jest już odwiedzony
        static bool CzyStanOdwiedzony(Stan stan, List<Stan> odwiedzoneStany)
        {
            foreach (Stan s in odwiedzoneStany)
            {
                if (s.misjonarzeLewa == stan.misjonarzeLewa && s.kanibaleLewa == stan.kanibaleLewa && s.statekNaLewymBrzegu == stan.statekNaLewymBrzegu)
                    return true;
            }
            return false;
        }

        // Rekurencyjnie znajduje rozwiązanie problemu
        static bool ZnajdzRozwiazanie(Stan aktualnyStan, List<Stan> odwiedzoneStany, List<Stan> rozwiazanie)
        {
            if (!CzyStanBezpieczny(aktualnyStan))
                return false;

            if (CzyStanCelem(aktualnyStan))
            {
                rozwiazanie.Add(aktualnyStan);
                return true;
            }

            odwiedzoneStany.Add(aktualnyStan);

            for (int i = 0; i <= 3; i++)
            {
                for (int j = 0; j <= 3; j++)
                {
                    if (i + j >= 1 && i + j <= 2) // Możemy przewieźć 1 lub 2 osoby na łódce
                    {
                        Stan nowyStan = WykonajRuch(aktualnyStan, i, j);

                        if (!CzyStanOdwiedzony(nowyStan, odwiedzoneStany))
                        {
                            List<Stan> noweRozwiazanie = new List<Stan>(rozwiazanie);
                            noweRozwiazanie.Add(aktualnyStan);

                            if (ZnajdzRozwiazanie(nowyStan, odwiedzoneStany, noweRozwiazanie))
                            {
                                rozwiazanie.Clear();
                                rozwiazanie.AddRange(noweRozwiazanie);
                                return true;
                            }
                        }
                    }
                }
            }

            return false;
        }

        static void Main(string[] args)
        {
            Stan poczatkowyStan = new Stan(3, 3, true); // Początkowy stan - 3 misjonarzy i 3 kanibale na lewym brzegu

            List<Stan> odwiedzoneStany = new List<Stan>();
            List<Stan> rozwiazanie = new List<Stan>();

            if (ZnajdzRozwiazanie(poczatkowyStan, odwiedzoneStany, rozwiazanie))
            {
                rozwiazanie.Reverse();

                Console.WriteLine("Rozwiązanie:");

                foreach (Stan stan in rozwiazanie)
                {
                    Console.WriteLine("Prawa strona: Misjonarze: {0}, Kanibale: {1}, Statek na lewym brzegu: {2}", stan.misjonarzeLewa, stan.kanibaleLewa, stan.statekNaLewymBrzegu);
                    Console.WriteLine("Lewa strona: Misjonarze: {0}, Kanibale: {1}\n", 3 - stan.misjonarzeLewa, 3 - stan.kanibaleLewa);
                }
            }
            else
            {
                Console.WriteLine("Nie znaleziono rozwiązania.");
            }

            Console.ReadLine();
        }
    }
}
