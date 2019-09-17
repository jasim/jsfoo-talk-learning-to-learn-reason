SLIDES := $(patsubst %.md,%.md.slides.pdf,$(wildcard *.md))
HANDOUTS := $(patsubst %.md,%.md.handout.pdf,$(wildcard *.md))
REVEAL := $(patsubst %.md,%.md.reveal.html,$(wildcard *.md))

all : $(SLIDES) $(HANDOUTS) ${REVEAL}

%.md.slides.pdf : %.md
	pandoc $^ -t beamer --slide-level 2 -o $@
	pandoc $^ -t beamer --slide-level 2 -o $@

%.md.reveal.html : %.md
	pandoc -t revealjs --slide-level 2 -s -o $@ $^ -V revealjs-url="." -V theme=serif
	ruby ./fixup-reveal.rb $@
	mv $@ ./reveal.js/index.html
	cp -R images ./reveal.js	

%.md.handout.pdf : %.md
	pandoc $^ -t beamer --slide-level 2 -V handout -o $@ 
	pdfnup $@ --nup 1x2 --no-landscape --keepinfo \
		--paper letterpaper --frame true --scale 0.9 \
		--suffix "nup"
	mv $*.md.handout-nup.pdf $@
		

clobber : 
	rm -f $(SLIDES)
	rm -f $(HANDOUTS)