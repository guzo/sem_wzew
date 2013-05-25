all: out/sem.pdf

view: all
	chronic okular out/sem.pdf &

edit:
	chronic kate *.tex &

spellcheck:
	for f in *.tex; do aspell --mode=tex --lang=pl --encoding=utf-8 check $$f; done

clean:
	-rm -v out/*

out/sem.pdf: sem.tex demo.tex part0.tex part1.tex part2.tex gfx/

out/%.pdf: %.tex
	pdflatex -output-directory $(dir $@) $< && \
	pdflatex -output-directory $(dir $@) $<

.PHONY: all view edit clean spellcheck
