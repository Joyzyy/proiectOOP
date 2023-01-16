from fpdf import FPDF
from datetime import date

def someFunction(data):

    data = data.split(";")

    id = data[0]
    tipBilet = data[1]
    nrLoc = data[2]
    nrRand = data[3]
    numeEveniment = data[4]
    numeLocatie = data[5]
    
    today = date.today()
    d1 = today.strftime("%d-%m-%Y")

    pdf = FPDF()
    pdf.add_page()
    pdf.set_font("Arial", size=12)
    pdf.cell(200, 10, txt="TICHET nr. " + id, ln=1, align="C")
    pdf.cell(200, 10, txt="Eveniment: " + numeEveniment, ln=1, align="C")
    pdf.cell(200, 10, txt="Locatie: " + numeLocatie, ln=1, align="C")
    pdf.cell(200, 10, txt="Tip bilet: " + tipBilet, ln=1, align="C")
    pdf.cell(200, 10, txt="Loc: " + nrLoc, ln=1, align="C")
    pdf.cell(200, 10, txt="Rand: " + nrRand, ln=1, align="C")
    pdf.output("Tichet_" + d1 + "_" + id + ".pdf")
    
    return 0