#Nome do Script a ser executado
SCRIPT_NAME = fractal.py

#comando para executar
run:
	python3 $(SCRIPT_NAME)


#Limpar os arquivos temporarios
clean:
	rm -f MandelMatrix.txt
	rm -f Parameter.txt
	rm -f fractal
