palavra = input()
if (palavra == palavra[::-1]) :
    print("Palindromo")
else :
    print("Nao Palindromo")

# sem espaços, acentos ou maiúsculas
palavra = input()
revisada = palavra.replace(" ", "").lower()
if (palavra == revisada[::-1]) :
    print("Palindromo")
else :
    print("Nao Palindromo")