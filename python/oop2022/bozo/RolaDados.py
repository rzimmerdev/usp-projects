import Dado as dd
import time

class RolaDados:


	def __init__(self, n = 5):
		self.dados = []
		for i in range(n):
			self.dados.append(dd.Dado())
			time.sleep(0.5)
			
	def __str__(self):
		s = ''
		for i in range(5):
			base = i * 8
			for d in self.dados:
				p = str(d)
				s += p[base:base+7]
				s += "    "
			s += '\n'
		return s
	
	def rolar(self, s = None):
		if s == None:
			r = []
			b = len(self.dados) * [True]
		else:
			r = s.split()
			b = len(self.dados) * [False]
		for k in r:
			try:
				i = int(k) - 1
			except ValueError :
				i = -1
			if i >= 0 and i < len(self.dados):
				b[i] = True
		return self.rolar_boolean(b)
	
	
	def rolar_boolean(self, quais = []):
		r = []
		i = 0
		for b in quais:
			if i >= len(self.dados):
				break
			if b:
				self.dados[i].rolar()
			r.append(self.dados[i].getLado())
			i += 1
		return r
		
	
if __name__ == '__main__':
	rd = RolaDados()
	print(rd)
	print(rd.rolar())
	print(rd)
	rd = RolaDados(3)
	print(rd)
	rd = RolaDados(7)
	print(rd)
	
