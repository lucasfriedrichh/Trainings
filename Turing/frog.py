def medirDist(posSapo, lingua, posMosca):
    ans=[]
    for i in range(len(posSapo)):
        soma = 0
        for j in range(len(posMosca)):
            if posSapo[i] == posMosca[j]:
                return True
            if posSapo > posMosca:
                distMosca = abs(posSapo[i] - posMosca[j])
            elif posMosca > posSapo:
                distMosca = abs(posMosca[j] - posSapo[i])
            else:
                soma +=1
                break

            if abs(lingua[i]) >= abs(distMosca):
                soma+=1
        ans.append(soma)
    return ans

posSapo  = [2, 3, 4]
lingua   = [1, 5, 6]
posMosca = [1, 5, 6]
ans = medirDist(posSapo, lingua, posMosca)
print(ans)