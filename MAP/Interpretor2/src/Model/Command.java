package Model;

public abstract class Command {

	private String key;
	private String description;
	
	public Command(String k, String d)
	{
		this.key=k;
		this.description=d;
	}
	
	public abstract void execute();
	public String getKey()
	{
		return this.key;
	}
	public String getDescription()
	{
		return this.description;
	}
}
