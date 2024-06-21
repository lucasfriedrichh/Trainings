grades = input().split()
a, b, c, d = grades
media = (float(a) * 2 + float(b) * 3 + float(c) * 4 + float(d) * 1) / 10

print(f"Media: {media:.1f}")

if media < 5:
   print("Aluno reprovado.")

if media >= 7:
   print(f"Aluno aprovado.")

if 5.0 <= media <= 6.9:
    print(f"Aluno em exame.")
    notaExame = float(input())
    print(f"Nota do exame: {notaExame}")
    mediaE = float((media+notaExame)/2)
    if mediaE>=5.0:
       print(f"Aluno aprovado.")
    else:
       print(f"Aluno reprovado.")
    print(f"Media final: {mediaE:.1f}")


