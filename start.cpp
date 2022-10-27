#include "Form.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute] int main(array<String^> ^ args) {
	 Application::EnableVisualStyles();
	 Application::SetCompatibleTextRenderingDefault(false);
	Project1::MyForm form;
	 Application::Run(% form);
	
		return 0;
	
}

System::Void Project1::MyForm::GenerateBtn_Click(System::Object ^ sender,
	System::EventArgs ^ e) {
	
		 if (matrix != nullptr) {
		 deleting_matrix(matrix);
		 matrix = nullptr;
		
	}
	

		matrix = creating_matrix(Convert::ToInt32(Rows -> Value),
			 Convert::ToInt32(Cols -> Value));
	
		if (FillMatrix -> SelectedItem == "випадковими числами") {
		dataGridView1 -> EditMode = DataGridViewEditMode::EditProgrammatically;
		randomization(matrix);
		
	}else if (FillMatrix -> SelectedItem == "власноруч") {
		dataGridView1 -> EditMode = DataGridViewEditMode::EditOnEnter;
		
	}
		else {
		 MessageBox::Show("Оберіть метод заповнення матриці!", "Помилка!", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation);
		 return System::Void();
		
	}
	

	dataGridView1 -> RowCount = matrix -> rows;
	 dataGridView1 -> ColumnCount = matrix -> cols;
	
		
		 for (int i = 0; i < matrix ->rows; i ++ ) {
		 for (int j = 0; j < matrix ->cols; j ++ ) {
			dataGridView1 -> Columns[j] -> HeaderCell -> Value = Convert::ToString(j + 1);
			dataGridView1 -> Rows[i] -> HeaderCell -> Value = Convert::ToString(i + 1);
			dataGridView1 -> Rows[i] -> Cells[j] -> Value = matrix -> data[i][j];
			
		}
		
	}
	 dataGridView1 -> AutoResizeRowHeadersWidth(
		 DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	 dataGridView1 -> AutoResizeColumns();
	
		 return System::Void();
	
}

 System::Void Project1::MyForm::ResultBtn_Click(System::Object ^ sender,
	 System::EventArgs ^ e) {
	 if (dataGridView1 -> EditMode == DataGridViewEditMode::EditOnEnter)
		 for (int i = 0; i < matrix ->rows; i ++ )
		 for (int j = 0; j < matrix ->cols; j ++ )
		 matrix -> data[i][j] =
		 Convert::ToInt32(dataGridView1 -> Rows[i] -> Cells[j] -> Value);
	
		MessageBox::Show(Convert::ToString(processing(matrix)), "Результат обчислення.",
			 MessageBoxButtons::OK, MessageBoxIcon::Information);
 return System::Void();

}
