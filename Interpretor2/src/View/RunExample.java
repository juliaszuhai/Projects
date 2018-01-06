package View;

import Controller.Controller;
import Model.Command;


public class RunExample extends Command {
	private Controller ctrl;
	public RunExample(String key,String desc,Controller ctrl)
	{
		super(key,desc);
		this.ctrl=ctrl;
	}
	

	@Override
	public void execute() {
		try{
			ctrl.allStep();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}

	}

}
