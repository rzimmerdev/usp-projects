####################################
#      DISTRIBUIÇÕES DISCRETAS     #
####################################

rm(list=ls())# Limpar o R 

# Diretorio
setwd("G:/.shortcut-targets-by-id/1kMb4Ow6nGzKQ18E5_2p2c3sTqqMvXjvX/SME0123 - ESTATÍSTICA I/AULAS PRATICAS")


set.seed(123) # semente do gerador de números aleatórios

#Distribuição Binomial
#Vamos simular o lançamento de n moedas e a probabilidade de sair k caras.
#Ou seja, termos k sucessos em n realizações de um experimento.

n = 100 # numero de lançamentos
p = 0.5 # probabilidade de sair cara
P = rbinom(1000,n,p)
k = seq(30,65,5)
x11()
par(mfrow = c(1, 2))
hist(P, prob = TRUE, xlab = "K", ylab = "P(K)", main = "Histograma Binomial")
curve(dbinom(x, n, p), type = "h",xlab = "x", ylab = "p(x)",
      col = "blue", lwd = 2, add = T)
plot(k, dbinom(k,n,p), type = "l", main = "Curva Teórica Binomial")


# Distribuição de Poisson
lbd = 10 # taxa
n = 1000 # numero de pontos extraídos de uma distribuição de Poisson
P = rpois(n,lbd)
x11()
par(mfrow = c(1, 2))
hist(P, prob = TRUE, xlab = "K", ylab = "P(K)", main = "Histograma Poisson")
k = seq(0,20,2)
curve(dpois(x, lbd), type = "h",xlab = "x", ylab = "p(x)",
      col = "blue", lwd = 2, add = T)
plot(k, dpois(k,lbd), type = "l",main = "Curva Poisson")

#Distribuição Geométrica
p = 0.2 # probabilidade de sucesso
n = 10000 # numero de pontos extraídos de uma distribuição de Geométrica
X = rgeom(n,p)
x11()
par(mfrow = c(1, 2))
hist(X, prob = TRUE, xlab = "K", ylab = "P(K)", main = "Histograma Geométrica")
k = seq(-3,15,2)
curve(dgeom(x, p), type = "h",xlab = "x", ylab = "p(x)",
      col = "blue", lwd = 2, add = T)
plot(k, dgeom(k,p), type = "l",main = "Curva Teórica Geométrica")


#Distribuição Hipergeométrica
N1 = 4 # number de elementos do tipo I
N2 = 21 # numero de elementos do tipo II
r = 5 # numero de objetos selecionados sem reposicao
n = 1000 # numero de pontos extraídos da distribuição hipergeométrica
X = rhyper(n,N1,N2,r)
x11()
par(mfrow = c(1, 2))
hist(X, prob = TRUE, xlab = "K", ylab = "P(K)", main = "Histograma Hipergeométrica")
k = seq(0,20,2)
curve(dhyper(x,N1,N2,r), type = "h",xlab = "x", ylab = "p(x)",
      col = "blue", lwd = 2, add = T)
plot(k, dhyper(k,N1,N2,r), type = "l",main = "Curva Teórica hipergeométrica")




