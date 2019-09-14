SLIDES := $(patsubst %.md,%.pdf,$(wildcard *.md))

all : $(SLIDES) 

%.pdf : %.md
	pandoc $^ -t beamer --slide-level 2 -o $@		

clobber : 
	rm -f $(SLIDES)
