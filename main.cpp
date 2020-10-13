#include <map>
#include "stb_csv_reader.h"
#include "stb_csv_writer.h"
#include "stb_utils.h"

int main(int argc, char** args)
{
  const string& customer_file = "./CUSTOMER.CSV";
  const string& smaller_customer_file = "./SMALLER_CUSTOMER.CSV";
  const string& invoice_file = "./INVOICE.CSV";
  const string& smaller_invoice_file = "./SMALLER_INVOICE.CSV";
  const string& invoice_item_file = "./INVOICE_ITEM.CSV";
  const string& smaller_invoice_item_file = "./SMALLER_INVOICE_ITEM.CSV";

  const string& sample_id_file = "./CUSTOMER_SAMPLE.CSV";
  
  stb_csv_reader id_reader(sample_id_file);
  
  //put the sample ids into map
  map<string, string> sample_ids;
  string text;
  
  id_reader.nextLine(text); //skip header
  while (id_reader.nextLine(text))
    sample_ids[text] = ""; 


  // smaller customer csv file
  stb_csv_reader customer_reader(customer_file);
  stb_csv_writer smaller_customer_writer(smaller_customer_file);
  if (customer_reader.nextLine(text)) {
    smaller_customer_writer.writeLine(text); // copy header
    while (customer_reader.nextLine(text)) {
      vector<string> tokens;
      stb_utils::parse_line(text, tokens);
      if (sample_ids.find(tokens[0]) != sample_ids.end()) {
        smaller_customer_writer.writeLine(text); 
      }
    }
  }

  // save sample invoice into a map to filter invoice item csv file
  map<string, string> sample_invoices;
  // smaller invoide csv file
  stb_csv_reader invoice_reader(invoice_file);
  stb_csv_writer smaller_invoice_writer(smaller_invoice_file);
  if (invoice_reader.nextLine(text)) {
    smaller_invoice_writer.writeLine(text); // copy header
    while (invoice_reader.nextLine(text)) {
      vector<string> tokens;
      stb_utils::parse_line(text, tokens);
      if (sample_ids.find(tokens[0]) != sample_ids.end()) {
        smaller_invoice_writer.writeLine(text);
        if (sample_invoices.find(tokens[1]) == sample_invoices.end()) {
          sample_invoices[tokens[1]] = "";
          cout << tokens[1] << endl;
        }
      }
    } 
  }

  // save sample invoice item csv file
  stb_csv_reader item_reader(invoice_item_file);
  stb_csv_writer smaller_item_writer(smaller_invoice_item_file);
  if (item_reader.nextLine(text)) {
    smaller_item_writer.writeLine(text); // copy header
    while (item_reader.nextLine(text)) {
      vector<string> tokens;
      stb_utils::parse_line(text, tokens);
      if (sample_invoices.find(tokens[0]) != sample_invoices.end())
        smaller_item_writer.writeLine(text);
    }
  }

  return 0;
}
