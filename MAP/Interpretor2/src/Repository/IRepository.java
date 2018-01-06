package Repository;
import Model.*;
public interface IRepository {
	public PrgState getState();
	public void logPrgStateExec() throws Exception;

}
