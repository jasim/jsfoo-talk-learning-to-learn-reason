SLIDES := $(patsubst %.md,%.md.slides.pdf,$(wildcard *.md))
HANDOUTS := $(patsubst %.md,%.md.handout.pdf,$(wildcard *.md))
REVEAL := $(patsubst %.md,%.md.reveal.html,$(wildcard *.md))

# add $(SLIDES) $(HANDOUTS) to make PDFs, but make sure
# to use all png instead of svg..

all : ${REVEAL}

%.md.slides.pdf : %.md
	pandoc $^ -t beamer --slide-level 2 -o $@
	pandoc $^ -t beamer --slide-level 2 -o $@

%.md.reveal.html : %.md
	pandoc -t revealjs --slide-level 2 -s -o $@ $^ -V revealjs-url="." -V theme=serif
	ruby ./fixup-reveal.rb $@
	mv $@ ./docs/index.html
	mv speaker_notes.html ./docs/speaker_notes.html
	cp -R images ./docs		

%.md.handout.pdf : %.md
	pandoc $^ -t beamer --slide-level 2 -V handout -o $@ 
	pdfnup $@ --nup 1x2 --no-landscape --keepinfo \
		--paper letterpaper --frame true --scale 0.9 \
		--suffix "nup"
	mv $*.md.handout-nup.pdf $@
		

clobber : 
	rm -f $(SLIDES)
	rm -f $(HANDOUTS)