from reportlab.lib.pagesizes import A4
from reportlab.pdfgen import canvas
from reportlab.lib.units import inch

def txt_to_pdf(txt_file, pdf_file):
    c = canvas.Canvas(pdf_file, pagesize=A4)
    width, height = A4
    margin = 0.7 * inch
    text = c.beginText(margin, height - margin)

    text.setFont("Courier", 10)  # built-in monospace font

    with open(txt_file, "r", encoding="utf-8") as f:
        for line in f:
            text.textLine(line.rstrip("\n"))

            # start a new page if near the bottom
            if text.getY() < margin:
                c.drawText(text)
                c.showPage()
                text = c.beginText(margin, height - margin)
                text.setFont("Courier", 10)

    c.drawText(text)
    c.save()
    print(f"✅ Converted {txt_file} → {pdf_file}")


if __name__ == "__main__":
    txt_file = input("Enter text file name: ").strip()
    pdf_file = txt_file.replace(".txt", ".pdf")
    txt_to_pdf(txt_file, pdf_file)
